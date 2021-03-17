#include <iostream>
#include <cmath>

/**
 * Ejercicio 11 Función Exponencial
 *
 * La función exponencial (e^x) se define mediante:
 *
 * exp(x) = 1 + x + x^2/2 + x^3/6 + ... + x^i/i + ...
 *
 * En particular para 0 ≤ x < 1 cada término es menor al anterior.
 * Implemente un algoritmo recursivo que obtenga una aproximación del valor e^x
 * truncando el cálculo al llegar a un término menor a una tolerancia
 * establecida.
 *
 * Además se debe devolver cuántos términos fueron necesarios para obtener el resultado.
 */

/**
 * Devuelve el factorial de n
 * no es recursivo :P
 */
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

float expN(float x, float tol, int &cantidad, int n) {
    cantidad++;

    float value = pow(x, n) / factorial(n);
    if (value < tol) return value;
    return value + expN(x, tol, cantidad, n + 1);
}

/**
 * Devuelve la aproximación de e^x hasta el término que sea menor a tol.
 *
 * Devuelve en 'cantidad' la cantidad de términos evaluados.
 */
float exp(float x, float tol, int &cantidad) {
    return expN(x, tol, cantidad, 0);
}

int main() {
    int cantidad = 0;
    float x = 0.4;
    float tol = 0.001;
    printf("e^%f = %f (con una tolerancia de %f)\n", x, exp(x, tol, cantidad), tol);
    printf("cantidad de elementos evaluados: %d", cantidad);
    return 0;
}
