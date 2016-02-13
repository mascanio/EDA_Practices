#include <iostream>
using namespace std;

class Date {
	int _day;
	int _mounth;
	int _year;
public:

	int diasMes(int mes) const {
		int r = 31;
		switch (mes)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			r = 30;
			break;
		case 2:
			r = 28; //bisiesto se cuenta fuera
			break;
		}

		return r;
	}
	// Dias para acabar el año desde la fecha actual
	int daysAcabarYear() const {
		int i = diasMes(_mounth) - _day;

		for (int j = _mounth +1; j < 13; j++)
			i+= diasMes(j);

		return i;
	}
	bool esBisiesto(int year) const {
		return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	}

	int numeroBisiestos (Date big) const {
		int i = _year;
		int j = big._year;
		int cont = 0;
		if (_mounth > 2 && esBisiesto(_year)) i = i + 1;
		if (big._mounth < 3 && big._day < 29
			&& esBisiesto(big._year)) j = j -1;

		while(i < j +1){
			if(esBisiesto(i)) cont++;
			i++;
		};
		return cont;
	}
	bool mayorQue (Date a) const{
		return (
			((_day > a._day) && (_mounth == a._mounth) && (_year == a._year)) ||
			((_mounth > a._mounth) && (_year == a._year)) ||
			(_year > a._year)
			);
	}
	bool igualQue(Date a) const{
		return (_day == a._day && _mounth == a._mounth && _year == a._year);
	}

	bool menorQue (Date a) const{
		return !mayorQue(a) && !igualQue(a);
	}

	/**
	Crea una fecha válida y que exista, si los parámetros de entrada no son válidos
	el que este mal se pondrá a 0 para poder indicar al usuario que lo corrija
	*/
	Date(int day,int moth,int year){

		if (year > 0)
			_year = year;
		else
			_year = 0;

		if (moth > 0 && moth < 13 )
			_mounth = moth;

		else{
			_mounth	= 0;

		}
		//validar dia
		if (day > 0 && (_day < diasMes(_mounth)) || 
			(_mounth == 2 && _day == 29 && esBisiesto(_year)))
			_day = day;
		else
			_day = 0; 
	}

	void printDay () const {
		cout << "day: " << _day << " moth: "  << _mounth << " year: " << _year << endl;
	}

	// resta
	int dayEntre (const Date& big) const {
		int solucion = 0;

		if(this->mayorQue(big)) 
			solucion = big.dayEntre(Date(_day,_mounth,_year));
		else {
			solucion = this->daysAcabarYear() + 365*(big._year - this->_year - 1) 
				+ numeroBisiestos(big) + (365 - big.daysAcabarYear());

		}
		return solucion;
	}

	bool dayBad(){return _day == 0;}
	bool mothBad(){return _mounth == 0;}
	bool yearBad(){return _year == 0;}
};


int main() {
	//1098

	Date ad = Date(3,5,1985);
	Date as = Date(1,2,2020);
	int i = ad.dayEntre(as);
	as.printDay();
	cout << i << endl;
	char b;
	cin>>b;
	return 0;
}