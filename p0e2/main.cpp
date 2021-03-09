#include <iostream>

/** Ejercicio 2 Primos
 *
 * Escriba un procedimiento que calcule e imprima en pantalla todos los números primos entre dos enteros
 *   positivos A y B cualesquiera.
 */


/*
 * Esta quizá no sea la mejor manera de comprobar si un número es primo o no.
 */
bool esPrimo(int numero) {
    if (numero < 2) return false;

    bool esPrimo = true;

    for (int i = numero - 1; i > 1; i--) {
        esPrimo = numero % i != 0;
        if (!esPrimo) break;
    }

    return esPrimo;
}

void imprimirPrimosEntre(int min, int max) {
    if (max < min) {
        int aux = min;
        min = max;
        max = aux;
    }

    if (max < 2) return;
    if (min < 2) {
        min = 1;
    }

    for (int i = min; i < max; i++) {
        if (esPrimo(i)) {
            printf("%i, ", i);
        }
    }
}

int main() {
    imprimirPrimosEntre(-100, 200);
    return 0;
}
