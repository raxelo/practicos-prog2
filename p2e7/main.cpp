#include <iostream>

/**
 * Ejercicio 7 Evaluación de Polinomio
 *
 * Implemente un algoritmo recursivo que evalúe un polinomio usando la regla de Horner:
 *
 * P(x) = a0 + x(a1 + x(a2 + · · · + (xan)· · ·))).
 *
 */

float horner(float *P, uint n, float x) {
    if (n == 0) return P[0];

    // Asumimos, por induccion, que queremos calcular horner(3) con horner(2)
    //  P(2) = a2 + x(a1 + x(a0))
    //  P(2) * x + a3 = a3 + x(a2 + x(a1 + x(a0))) = P(3)
    return horner(P, n - 1, x) * x + P[n];
}

int main() {
    float *p = new float[3]{2,3,4};             // p(x) = 2x^2 + 3x + 4
    printf("%f", horner(p, 2, 7));        // p(7) = 123
    return 0;
}
