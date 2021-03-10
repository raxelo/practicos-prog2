#include <iostream>
#include "Lista.h"

/**
 * Ejercicio 3 Tad Lista de naturales
 *
 * Considere el siguiente conjunto de operaciones que especifican al TAD Lista de naturales.
 *
 * VER Lista.h 👀
 */


/** Utilizando las operaciones presentadas implemente las siguientes operaciones:
 *
 * (a) descartar que retorna la lista resultado de no tomar los primeros i elementos. Si la lista l tiene i o
 *   menos de i elementos devuelve la lista vacía.
 * (b) largo que dada una lista l, retorna la cantidad de elementos de la misma
 * (c) insertarFinal que inserta un elemento al final de la lista.
 * (d) unir que agrega la lista p al final de la lista l.
 * (e) invertir que dada una lista l, retorna el resultado de invertirla.
 * (f) cambiar que retorna la lista resultado de cambiar el valor x (cada vez que aparece) por el valor y en la
 *   lista l.
 *
 */

/**
 * (a) descartar
 *
 * Retorna la lista resultado de no tomar los primeros i elementos.
 * Si la lista tiene i o menos de i elementos, devuelve la lista vacía.
 *
 * @param i el índice
 * @param lista la lista
 * @return la lista resultado
 */
Lista descartar(int i, Lista lista) {
    if (esVacia(lista)) return lista;

    Lista resultado = lista;

    int j = 0;
    while (estaDefinida(j, lista) && j++ < 3) {
        eliminar(0, lista);
    }

    return resultado;
}

/**
 * (b) largo
 *
 * Retorna la longitud de una lista.
 *
 * @param l la lista
 * @return la longitud
 */
int largo(Lista l) {
    int largo = 0;
    while (estaDefinida(largo, l)) {
        largo++;
    }

    return largo;
}

/**
 * (c) insertarFinal
 *
 * Inserta un elemento al final de la lista.
 *
 * @param elemento elemento a insertar
 * @param lista
 */
void insertarFinal(int elemento, Lista lista) {
    int i = 0;
    while (estaDefinida(i, lista)) {
        i++;
    }
    insertar(elemento, i, lista);
}

/**
 * (d) unir
 *
 * Agrega la lista p al final de la lista l
 *
 * @param p lista
 * @param l lista
 */
void unir(Lista p, Lista l) {
    int i = 0;
    while (estaDefinida(i, l)) {
        i++;
    }

    int j = 0;
    while (estaDefinida(j, p)) {
        insertar(i, obtener(j, p), l);
        j++;
    }
}

/**
 * (e) invertir
 *
 * Dada una lista l, retorna el resultado de invertirla.
 *
 * @param l la lista
 * @return la lista invertida
 */
Lista invertir(Lista l) {
    if (esVacia(l)) return l;

    Lista resultado = crearLista();
    int listSize = largo(l);

    for (int i = listSize; i > 0; i--) {
        int elemento = obtener(i - 1, l);
        insertarFinal(elemento, resultado);
    }

    return resultado;
}

/**
 * (f) cambiar
 *
 * Retorna la lista resultado de cambiar el valor x (cada vez que aparece)
 * por el valor y en la lista l
 *
 * @param x
 * @param y
 * @param l
 * @return la lista con los valores cambiados
 */
Lista cambiar(int x, int y, Lista l) {
    if (esVacia(l)) return l;

    Lista nueva = crearLista();
    int longitud = largo(l);

    for (int i = 0; i < longitud; i++) {
        int valor = obtener(i, l);
        insertarFinal(valor == x ? y : valor, nueva);
    }

    return nueva;
}

int main() {
    return 0;
}





































