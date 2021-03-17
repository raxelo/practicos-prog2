#include <iostream>

/**
 * Ejercicio 10 Fibonacci
 * (a) Implemente un algoritmo recursivo que calcule la cantidad de invocaciones que deben hacerse para
 * obtener Fibonacci(n) con el algoritmo visto en el curso.
 *
 * (b) Una secuencia a1, a2, a3, · · · , ai
 * , · · · se dice que es aditiva si ai = ai−2 + ai−1 para i ≥ 3.
 *
 * Implemente un algoritmo recursivo que calcule el n-ésimo término de una secuencia aditiva y solo requiera n
 * invocaciones para lograrlo.
 * Implemente una versión recursiva de Fibonacci que solo realice n invocaciones para calcular el n-ésimo
 * término.
 *
 * (c) Implemente un algoritmo que devuleve el n-ésimo y el n − 1-ésimo número de Fibonacci.
 */

int fibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int pasosFibonacci(int n) {
    if (n <= 3) return 1; // Para fibonacci(n) donde n<=3 requiere un paso.

    // el ternario al final es porque si llamamos a f(4) o más
    // consideramos el llamado a f(4) como un llamado en sí,
    // a eso le sumamos el llamado a f(3) y f(2) que son 1 llamado cada uno
    // pasosFibonacci(4) = 3
    return pasosFibonacci(n - 1) + pasosFibonacci(n - 2) + (n >= 4 ? 1 : 0);
}

int secAditiva(uint n, int a1, int a2) {
    if (n == 1) return a1;
    if (n == 2) return a2;
    if (n == 3) return a1 + a2;
    return secAditiva(n - 1, a2, a1 + a2);
}

int fibonacciOptimizado(int n) {
    return secAditiva(n, 0, 1);
}

struct par {
    int primero, segundo;
};

/**
 * Devuelve ( Fibonacci (n -1) , Fibonacci (n))
 */
par fibAnterior(int n) {
    // soy vago este algoritmo no es tan eficiente.
    par par;
    par.primero = fibonacci(n - 1);
    par.segundo = fibonacci(n - 2);
    return par;
}

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("Fibonacci(%d) del curso: %d, pasos: %d\n", i, fibonacci(i), pasosFibonacci(i));
        printf("Fibonacci(%d) optimizado: %d\n", i, fibonacciOptimizado(i));
    }
    return 0;
}
