#include <iostream>

/**
 * Ejercicio 9 Vasos alternados
 *
 * Se tiene una disposición de n vasos, donde n es par. Los vasos de la primera mitad están llenos y los de
 * la segunda mitad están vacíos. Se quiere dejar los vasos alternados: los vasos de las posiciones impares
 * deben quedar llenos y los de las posiciones pares deben quedar vacíos. Sólo se permite verter el contenido
 * de vasos en otros (es decir, no se puede desplazar vasos).
 *
 * Implemente un algoritmo recursivo que resuelva el problema. En la siguiente especificación el valor true
 * representa un vaso lleno y el valor false un vaso vacío.
 */

/**
 * Modifica V. Solo se permite intercambio entre posiciones .
 *
 * Precondición: n % 2 == 0
 * V [1.. n/2] = { true } , V[n/2 + 1.. n] = { false }.
 * Postcondición: V[i] = true si y solo si i%2 == 1.
 *
 */
void vasos(bool *V, int start, int end) {
    // Caso base
    if (start >= end) return;

    // podemos asumir por inducción que se cumple para n-1
    // es decir el subconjunto de vasos
    vasos(V, start+1, end-1);

    if (start % 2 != 0) return;

    // cambiazo
    V[start] = false;
    V[end] = true;
}

void printVasos(bool *V, int size) {
    for (int i = 1; i <= size; i++) {
        printf(V[i] ? "T" : "F");
        printf(" ");
    }
}

int main() {
    bool *v = new bool[100];
    v[1] = true;
    v[2] = true;
    v[3] = true;
    v[4] = false;
    v[5] = false;
    v[6] = false;

    printVasos(v, 6);
    printf("\n");
    vasos(v, 1, 6);
    printVasos(v, 6);
    return 0;
}
