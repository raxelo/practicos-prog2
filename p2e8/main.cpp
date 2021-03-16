#include <iostream>

/**
 * Ejercicio 8 Combinaciones
 *
 * Implemente un algoritmo recursivo que calcule las combinaciones de m tomadas de a n, donde m ≥ n.
 *
 * Asuma las siguientes ecuaciones:
 *  - C(m, m) = 1
 *  - C(m, 0) = 1
 *  - C(m, 1) = m
 *  - C(m, n) = C(m − 1, n) + C(m − 1, n − 1), si m > n > 0
 *
 * NOTA: la expresión utilizada en el paso recursivo se conoce como Identidad de Pascal
 */

int c(int m, int n) {
    if (m == n) return 1;
    if (n == 0) return 1;
    if (n == 1) return m;

    return c(m - 1, n) + c(m - 1, n - 1);
}

int main() {
    printf("%d", c(5,3));
    return 0;
}
