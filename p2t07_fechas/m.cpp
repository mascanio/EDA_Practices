#include <iostream>

class Fecha {
    int _d;
    
    static bool divide(int n, int m) {
        return (n % m) == 0;
    }
    static bool bisiesto(int anyo) {
        return divide(anyo, 4) && ( ! divide(anyo, 100) || divide(anyo, 400));
    }
    static int diasMes(int anyo, int mes) {
        switch (mes) {
            case 1: // enero
            case 3: // marzo
            case 5: // mayo
            case 7: // julio
            case 8: // agosto
            case 10: // octubre
            case 12: // diciembre
                return 31;
            case 4: // abril
            case 6: // junio
            case 9: // septiembre
            case 11: // noviembre
                return 30;
            case 2: // febrero
                return bisiesto(anyo) ? 29 : 28;
            default:
                std::cout << "Error: mes " << mes << " de " << anyo << " no existe " << std::endl;
                return -100000;
        }
    }
    static bool esValida(int anyo, int mes, int dia) {    
        return anyo >= 1900 && anyo < 3000 
            && mes > 0 && mes <= 12 
            && dia > 0 && dia <= diasMes(anyo, mes);
    }
    static int diasAnyo(int anyo) {
        return bisiesto(anyo) ? 366 : 365;
    }
public:
    Fecha(int anyo, int mes, int dia) {
        _d = dia-1;
        for (int i=1; i<mes; i++) {
            _d += diasMes(anyo, i);
        }
        for (int i=1900; i<anyo; i++) {
            _d += diasAnyo(i);
        }
//         std::cout << "[ " << _d << " ] " << std::endl;
    }
    int operator-(const Fecha &otra) const {
        return _d - otra._d;
    }
};

using namespace std;
int main() {
        int a, b, c;
        cin >> a >> b >> c;
        while (a) {
            Fecha f(c, b, a);
            cin >> a >> b >> c;
            int d = Fecha(c, b, a) - f;
            cout << d << (d != 1 ? " dias." : " dia.") << endl;
            cin >> a >> b >> c;
        }
        return 0;
}
