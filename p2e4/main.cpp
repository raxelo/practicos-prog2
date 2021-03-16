#include <iostream>

/**
 * Ejercicio 4 Máximo Común Divisor
 *
 * Implemente un algoritmo recursivo que calcule el máximo común divisor de dos enteros positivos.
 */

int maximoComunDivisor(int num1, int num2) {
    if (num2 == 0) return num1;
    return maximoComunDivisor(num2, num1%num2);
}

int main() {
    printf("%d", maximoComunDivisor(9, 6));
    return 0;
}
