#include <iostream>
#include <ctime>
#include <cstdlib>

#include "conjunto_bueno.h"
#include "conjunto_malo.h"

using namespace std;

int main() {
    
    srand((unsigned int)time(0));
    
    ConjuntoBueno<int> cb = ConjuntoBueno<int>();
    ConjuntoMalo<int> cm = ConjuntoMalo<int>();
    
    for (int i=0; i < 8; i++) {
        int r = (rand() % 10) + 1;
        cb.inserta(r);
        cm.inserta(r);
        cout << "tras insertar " << r << endl;
        cb.muestra();
        cm.muestra();
    }
    
    for (int i = 0; i < 8; i++) {
        int r = (rand() % 10) + 1;
        if (cb.contiene(r)) {
            cb.elimina(r);
        }
        if (cm.contiene(r)) {
            cm.elimina(r);
        }
        cout << "tras intentar eliminar " << r << endl;
        cb.muestra();
        cm.muestra();
    }
    
    return 0;
}