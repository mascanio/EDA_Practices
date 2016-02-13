#include <iostream>
#include <cstdlib>

#include "Pila.h"

using namespace std;

bool dame2(Pila<int> &p, int &uno, int &otro, bool ceroEsValido=true) {
	if ( ! p.esVacia()) {
		uno = p.cima();
		p.desapila();
		if (! p.esVacia() && (ceroEsValido || uno != 0)) {
			otro = p.cima();
			p.desapila();
			// todo bien
			return true;
		} else {
			p.apila(uno);
		}
	}
	// errores
	return false;		
}

int main() {
	Pila<int> p;

	bool quiereSalir = false;
	bool ok = true;
	string s;
	while (!quiereSalir) {
		cin >> s;
		int uno, otro;
		switch (s[0]) {
			case '+':
				if (ok = dame2(p, uno, otro)) {
					p.apila(otro + uno);
				}
				break;
			case '-':
				if (ok = dame2(p, uno, otro)) {
					p.apila(otro - uno);
				}
				break;
			case '*':
				if (ok = dame2(p, uno, otro)) {
					p.apila(otro * uno);
				}
				break;
			case '/':				
				if (ok = dame2(p, uno, otro, false)) {
					p.apila(otro / uno);
				}
				break;
			case '!':
				quiereSalir = true;
				break;
			case '$':
				if ( ! ok || p.esVacia()) {
					cout << "Error." << endl;
				} else {
					cout << p.cima() << endl;
				}
				break;
			default:
				p.apila(atoi(s.c_str()));
				ok = true;
				break;
		}
	}
	return 0;
}