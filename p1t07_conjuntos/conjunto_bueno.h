#ifndef _CONJUNTO_BUENO_H
#define _CONJUNTO_BUENO_H

#include <iostream>

#include "excepciones.h"

template <class E>
class ConjuntoBueno {
    /** max. de elementos */
    static const unsigned int MAX = 1000;
    unsigned int _tam;           /**< numero de elementos actuales */
    E _elementos[MAX];           /**< vector estatico de elementos */
    
    /**
     * Busca un elemento 'e' entre lo y hi, hi exclusive
     * Devuelve su pos (o donde tendria que ir); y true si lo encuentra
     */
    bool busca(const E &e, int lo, int hi, int &pos) const {
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (_elementos[m] < e) {
                lo = m+1;
            } else {
                hi = m;
            }
        }
        
        pos = lo;
        return (_elementos[pos] == e);
    }
    
public:
    
    ConjuntoBueno () { _tam = 0; }
    
    /**
     * Inserta un elemento en el conjunto
     * (mutador parcial; si no cabe, lanza ConjuntoLleno)
     */
    void inserta(const E &e) {
        if (_tam == MAX) throw ConjuntoLleno();
        
        int pos;
        busca(e, 0, _tam, pos);
        // hace espacio
        for (unsigned int i = _tam; i > (unsigned int)pos; i--) {
            _elementos[i] = _elementos[i-1];
        }
        _tam++;
        // inserta elemento en su posicion
        _elementos[pos] = e;
    }
    
    /**
     * Borra un elemento del conjunto
     * (mutador parcial; si no existe, lanza ElementoInvalido)
     */
    void elimina(const E &e) {
        int pos;
        if ( ! busca(e, 0, _tam, pos)) throw ElementoInvalido();
        // elimina espacio (y elemento)
        for (unsigned int i = pos; i < _tam-1; i++) {
            _elementos[i] = _elementos[i+1];
        }
        _tam --;
    }
    
    /**
     * Devuelve true si el elemento esta contenido en el conjunto
     * (observador)
     */
    bool contiene(const E &e) const {
        int pos;
        return busca(e, 0, _tam, pos);
    }
    
    /**
     * Muestra el contenido
     * (observador)
     */
    void muestra() const {
        for (unsigned int i = 0; i < _tam; i++) {
            std::cout << _elementos[i] << " ";
        }
        std::cout << std::endl;
    }
};
#endif //_CONJUNTO_BUENO_H