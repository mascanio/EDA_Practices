#ifndef _CONJUNTO_MALO_H
#define _CONJUNTO_MALO_H

#include <iostream>

#include "excepciones.h"

template <class E>
class ConjuntoMalo {
    static const unsigned int MAX = 1000;  /**< max. de elementos */
    unsigned int _tam;            /**< numero de elementos actuales */
    E _elementos[MAX];            /**< vector estatico de elementos */
    
    /**
     * Busca la posicion de un elemento e
     * @param e elemento a buscar
     * @return posicion del elemento, o -1 si no lo encuentra
     */
    int busca(const E &e) const {
        int posicion = -1;
        for (unsigned int i=0; i<_tam && posicion == -1; i++) {
            if (_elementos[i] == e) {
                posicion = i;
            }
        }
        return posicion;
    }
public:
    
    /**
     * Inicializa un conjunto vacío (constructor).
     */
    ConjuntoMalo() { _tam = 0; }
    
    /**
     * Inserta un elemento en la el conjunto
     * (mutador parcial; si se llena, lanza ConjuntoLleno).
     * @param e elemento a insertar
     */
    void inserta(const E &e) {
        if (_tam == MAX) throw ConjuntoLleno();
        _elementos[_tam] = e;
        _tam ++;
    }
    
    /**
     * Borra un elemento del conjunto
     * (mutador parcial; si no existe, lanza ElementoInvalido)
     */
    void elimina(const E &e) {
        int posicion = busca(e);
        if (posicion == -1) throw ElementoInvalido();
        
        // paso el ultimo elemento a su lugar
        _elementos[posicion] = _elementos[_tam-1];
        _tam --;
    }
    
    /**
     * Devuelve true si el elemento está contenido en el conjunto
     * (observador)
     */
    bool contiene(const E &e) const {
        return busca(e) != -1;
    }
    
    /**
     * Muestra el contenido
     * (observador)
     */
    void muestra() const {
        for (unsigned int i = 0; i < _tam; i++){
            std::cout << _elementos[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif //_CONJUNTO_MALO_H
