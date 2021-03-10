#include <iostream>
#include "Pila.h"

/**
 * Ejercicio 1 TAD Pila de enteros
 *
 * Considere el siguiente conjunto de operaciones que especifican al TAD Pila de enteros.
 *
 * VER Pila.h 👀
 */

/**
 * Utilizando las operaciones presentadas implemente las siguientes operaciones:
 *
 * (a) imprimir: dada una Pila p imprime los elementos de la misma.
 * (b) cantidad: dados un entero x y una Pila p, cuenta las ocurrencias del entero x en la Pila p
 * (c) cambiar: dados dos enteros x e y, y una Pila p, retorna el resultado de cambiar el elemento x (cada
 *   vez que aparece) por el elemento y en la Pila p.
 * (d) iguales: dadas dos Pilas p1 y p2, verifica si son iguales
 *
 */

/**
 * (a) imprimir
 * dada una Pila p imprime los elementos de la misma.
 * @param pila
 */
void imprimir(Pila pila) {
    Pila copia = pila;
    while (!esVacia(copia)) {
        printf("%d", cima(copia));
        copia = desapilar(copia);
        if (!esVacia(copia)) printf(", ");
    }
}

/**
 * (b) cantidad:
 * dados un entero x y una Pila p, cuenta las ocurrencias del entero x en la Pila p
 *
 * @param pila
 * @param x
 */
int cantidad(Pila pila, int x) {
    Pila copia = pila;
    int count = 0;
    while (!esVacia(copia)) {
        if (cima(copia) == x) count++;
        copia = desapilar(copia);
    }
    return count;
}

/**
 * (c) cambiar:
 * dados dos enteros x e y, y una Pila p, retorna el resultado de cambiar el
 * elemento x (cada vez que aparece) por el elemento y en la Pila p.
 *
 * @param pila
 * @param x el entero que se desea cambiar
 * @param y el reemplazo
 */
Pila cambiar(Pila pila, int x, int y) {
    Pila invertida = crearPila();
    Pila copia = pila;
    while (!esVacia(copia)) {
        int numero = cima(copia) == x ? y : numero;
        invertida = apilar(numero, invertida);
        copia = desapilar(copia);
    }

    while (!esVacia(invertida)) {
        copia = apilar(cima(invertida), copia);
        invertida = desapilar(invertida);
    }

    return copia;
}

/**
 * (d) iguales:
 * dadas dos Pilas p1 y p2, verifica si son iguales
 *
 * @param p1
 * @param p2
 *
 * @return si son iguales o no
 */
bool iguales(Pila p1, Pila p2) {
    Pila copia1 = p1;
    Pila copia2 = p2;

    bool iguales = true;
    while (!esVacia(copia1) && !esVacia(copia2) && iguales) {
        iguales = cima(copia1) == cima(copia2);
        desapilar(copia1);
        desapilar(copia2);
    }

    return iguales && esVacia(copia1) && esVacia(copia2);
}

int main() {
    return 0;
}
