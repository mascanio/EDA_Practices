#include <iostream>
#include <sstream>
#include "Pila.h"

using namespace std;

/**
 * Devuelve la siguiente "palabra XML",
 * excluyendo el < inicial y el > final
 */
string leePalabra(const string &texto, unsigned int &pos) {
    while (texto[pos] != '<') {
        pos ++;
    }
    int inicio = pos;
    while (texto[pos] != '>') {
        pos ++;
    }
    int final = pos;
    // constructor que toma cadena, inicio, y longitud
    return string(texto, inicio+1, final-inicio-1);
}

bool empareja(const string &texto) {
    Pila<string> p;
    unsigned int pos = 0;
    bool error = false;
    while ( ! error && pos < texto.length() - 2) {
        string palabra = leePalabra(texto, pos);
        if (palabra[0] == '/') {
            if (p.esVacia()) {
                cout << "Error: intento de cerrar <" << palabra << "> "
                     << "sin haberla abierto antes en pos. " << pos << endl;                
                error = true;
            } else if (palabra.compare(1, p.cima().length(), p.cima())) {
                cout << "Error: etiqueta <" << p.cima()
                     << "> se intenta cerrar con <" << palabra << "> en pos. "
                     << pos << endl;
                error = true;
            } else {
                p.desapila();
            }
        } else if (palabra[palabra.length()-1] != '/') {
            p.apila(palabra);
        }
    }
    if ( !error && ! p.esVacia()) {
        cout << "Error: etiqueta <" << p.cima()
             << "> sin cerrar al acabar el documento" << endl;
        error = true;
    }
    return ! error;
}

int main() {
    while ( ! cin.eof()) {
        string texto;
        getline(cin, texto);
        if (texto.length() > 1 && ! cin.eof() && empareja(texto)) {
            cout << "XML correcto" << endl;
        }
    }
    return 0;
}
