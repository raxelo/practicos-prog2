#include <iostream>
#include "Cola.h"

/**
 * Ejercicio 2 Tad Cola de naturales
 *
 * Considere el siguiente conjunto de operaciones que especifican al TAD Cola de naturales.
 *
 * VER Cola.h 👀
 */

/**
 * Utilizando las operaciones presentadas implemente las siguientes operaciones:
 * (a) maximo: dada una Cola c no vacía, retorna su máximo elemento.
 * (b) estaOrdenada: dada una Cola c, verifica si está ordenada de menor a mayor.
 * (c) cambiar: dados dos enteros x e y, y una Cola c, retorna el resultado de cambiar el elemento x (cada
 *  vez que aparece) por el elemento y en la Cola c.
 * (d) merge: dadas dos Colas ordenadas c1 y c2, genera una nueva cola intercalando ordenadamente ambas
 *  colas
 */

/**
 * (a) maximo
 *
 * @param c La cola
 * @return su máximo elemento.
 */
unsigned int maximo(Cola c) {
    Cola copia = c;
    unsigned int max = 0;

    while (!esVacia(copia)) {
        unsigned int numero = frente(copia);
        if (numero > max) max = numero;

        copia = desencolar(copia);
    }

    return max;
}

/**
 * (b) estaOrdenada
 *
 * @param c La cola
 * @return si está ordenada o no
 */
bool estaOrdenada(Cola c) {
    Cola copia = c;
    bool ordenada = true;
    unsigned int min = 0;

    while (ordenada && !esVacia(copia)) {
        ordenada = frente(copia) >= min;
        min = frente(copia);
        copia = desencolar(copia);
    }

    return ordenada;
}

/**
 * (c) cambiar
 *
 * @param x el valor que se desea cambiar
 * @param y el reemplazo
 * @param c la cola
 * @return Una cola con los elementos x cambiados por y
 */
Cola cambiar(unsigned int x, unsigned int y, Cola c) {
    Cola resultado = crearCola();
    Cola copia = c;

    while (!esVacia(copia)) {
        unsigned int frenteCola = frente(copia);
        resultado = encolar(frenteCola == x ? y : frenteCola, resultado);
        copia = desencolar(copia);
    }

    return resultado;
}

/**
 * (d) merge
 *
 * Dadas dos colas ordenadas, genera una nueva cola intercalando
 * ordenadamente ambas colas
 *
 * @param c1 cola ordenada 1
 * @param c2 cola ordenada 2
 *
 * @return una cola con los elementos ordenados de ambas colas.
 *
 */
Cola merge(Cola c1, Cola c2) {
    Cola resultado = crearCola();
    Cola copia1 = c1;
    Cola copia2 = c2;

    while (!esVacia(copia1) || !esVacia(copia2)) {
        unsigned int menor;

        if (!esVacia(copia1) && !esVacia(copia2)) {
            bool primeraMenor = frente(copia1) <= frente(copia2);
            menor = primeraMenor ? frente(copia1) : frente(copia2);
            unsigned int mayor = primeraMenor ? frente(copia2) : frente(copia1);
            encolar(menor, resultado);
            encolar(mayor, resultado);
        } else {
            menor = !esVacia(copia1) ? frente(copia1) : frente(copia2);
            encolar(menor, resultado);
        }

        if (!esVacia(copia1)) desencolar(copia1);
        if (!esVacia(copia2)) desencolar(copia2);
    }

    return resultado;
}

int main() {
    return 0;
}






































