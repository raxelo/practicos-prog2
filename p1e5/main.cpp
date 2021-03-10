#include <iostream>
#include "Pila.h"
#include "Cola.h"

/**
 * Ejercicio 5 - Ejercicio de examen (Diciembre 2018)
 *
 * Se desea saber si una pila y una cola tienen exactamente los mismos elementos y fueron insertados en ellas
 *   exactamente en el mismo orden. Para esto implemente la función mismosElementos usando las operaciones
 *   de los TADs Pila y Cola. Al terminar, p y c deben quedar vacías. Los elementos de Pila y Cola son de un
 *   tipo genérico que admite los usuales operadores de comparación.
 *
 * bool mismosElementos(Pila p, Cola c);
 *
 * No se deben hacer comparaciones innecesarias. No se pueden usar funciones auxiliares.
 *
 */

/**
 * mismosElementos
 *
 * Retorna un boolean que indica si la pila "p" y la cola "c" contienen
 * los mismos elementos y fueron insertados en el mismo orden.
 *
 * Además, debe vaciar "p" y "c".
 *
 * @param p la pila
 * @param c la cola
 * @return si tienen los mismos elementos y fueron insertados en el mismo orden
 */
bool mismosElementos(Pila p, Cola c) {
    if (esVacia(p) && esVacia(c)) return true;

    if (esVacia(p) && !esVacia(c) || !esVacia(p) && esVacia(c)) {
        return false;
    }

    /* Entiendo que por "insertados en el mismo orden"
     * la cima de la pila es el ultimo elemento de la cola
     * ya que la pila es LIFO y la cola es FIFO.
     *
     * Si agrego los numeros del 1 al 4, en orden
     * a la pila P y la cola C, lo visualizo así:
     *
     *   P     C
     * [ 4 ] [ 1 ] | frente de la cola o cima de la pila
     * [ 3 ] [ 2 ]
     * [ 2 ] [ 3 ]
     * [ 1 ] [ 4 ]
     *
     * y considero que mismosElementos(P, C) es true.
     */

    /* Se me ocurre crear otra pila invertida "I" e insertar en ella
     * uno a uno los elementos de P, de modo que quede invertida.
     *
     * Luego comprobar elemento a elemento de I con C.
     *
     *   I     C
     * [ 1 ] [ 1 ] | frente de la cola o cima de la pila
     * [ 2 ] [ 2 ]
     * [ 3 ] [ 3 ]
     * [ 4 ] [ 4 ]
     *
     */

    Pila invertida = crearPila();
    while (!esVacia(p)) {
        apilar(cima(p), invertida);
        desapilar(p);
    }

    bool iguales = true;
    while (!esVacia(c)) {
        int elementoEnCola = frente(c);
        desencolar(c);

        if (!iguales) continue; // no hacemos break porque nos piden vaciar "c".

        int elementoEnPila = cima(invertida);

        iguales = elementoEnPila == elementoEnCola;

        desapilar(invertida);
        // check adicional por si "invertida" se vació antes que "c",
        // el código sería mucho más simple sin el requerimiento de vaciar "p" y "c".
        if (!esVacia(c) && esVacia(invertida)) {
            iguales = false;
        }
    }

    // invertida debe estar vacía, de lo contrario puede que "c" esté incluida en "invertida"
    // y un conjunto sea más grande que el otro.
    return iguales && esVacia(invertida);
}

int main() {
    return 0;
}
