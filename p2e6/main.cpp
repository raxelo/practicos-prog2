#include <iostream>

/**
 * Ejercicio 6 Factorial
 *
 * La versión recursiva vista de factorial no presenta recursión de cola. Use un acumulador para obtener
 * una versión recursiva que presente recursión de cola.
 *
 */

/**
 * Devuelve el producto de factorial (n) por 'acum'.
 */
uint factAcum(uint n, int acum) {
    if (n == 1) return 1 * acum;

    return n * factAcum(n - 1, acum);
}

int main() {
    printf("%d", factAcum(4, 2));
    return 0;
}
