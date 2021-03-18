#include <iostream>

/**
 * Ejercicio 12 Regla graduada
 *
 * Se considera una regla graduada en la que la longitud de las marcas indica la
 * importancia, esto es, a las posiciones enteras corresponde longitud máxima, p,
 * a las posiciones de la forma x,5 corresponde longitud p − 1, a las posiciones de
 * la forma x,25 o x,75 corresponde longitud p − 2, etc. Implemente un algoritmo
 * recursivo que imprima las marcas entre dos posiciones enteras, ambas incluidas.
 * La longitud de las marcas para las posiciones enteras, p, es un parámetro. A la
 * derecha se ve el resultado esperado para p = 4.
 *
 */

void print(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

void reglaGraduadaAux(int p) {
    if (p <= 0) return;

    reglaGraduadaAux(p-1);
    print(p);
    reglaGraduadaAux(p-1);
}

void reglaGraduada(int p) {
    print(p);
    reglaGraduadaAux(p-1);
    print(p);
}

int main() {
    reglaGraduada(6);
    return 0;
}