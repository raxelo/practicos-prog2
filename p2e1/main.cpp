#include <iostream>

/**
 * Ejercicio 1 Insertion Sort
 *
 * Solo hago a,b,d. No hago la c 😉
 *
 * (a) Implemente de forma recursiva la función ordenar,
 * utilizando la función auxiliar insertarOrdenado.
 *
 * (b) Implemente la función auxiliar insertarOrdenado utilizando recursión.
 * (d) Transforme el algoritmo recursivo de la función auxiliar insertarOrdenado en iterativo
 *
 */

/**
 * Inserta e en A [1.. n+1] de manera ordenada.
 * Precondición: n>=0.
 * Si n>=1 => A [1.. n] está ordenado de manera creciente.
 * A[n+1] es indeterminado.
 * Postcondición: A [1.. n+1] queda ordenado de manera creciente.
 * @param A un arreglo de floats
 * @param n longitud del arreglo
 * @param e valor a insertar
 */
void insertarOrdenado(float *A, uint n, float e) {
    // Me quedé sin elementos, o llegué a un elemento menor o igual a e.
    if (n == 0 || e >= A[n]) {
        A[n+1] = e;
        return;
    }

    // El elemento no debia ser insertado en la posición N+1.
    // Por tanto, vamos a probar insertarlo en la posición N.

    // Tenemos mover el N-esimo elemento hacia adelante.
    A[n+1] = A[n];
    insertarOrdenado(A, n-1, e);
}

/**
 * Ordena el arreglo de floats.
 *
 * @param A un arreglo de floats
 * @param n longitud del arreglo
 */
void ordenar(float *A, uint n) {
    if (n <= 0) return;
    ordenar(A, n-1);
    insertarOrdenado(A, n-1, A[n]);
}

void print(float *array, int size) {
    for (int i = 1; i <= size; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}

int main() {
    const uint size = 5;
    float *a = new float[100];
    a[1] = 2;
    a[2] = 8;
    a[3] = 12;
    a[4] = 16;
    a[5] = 20;

    // Probamos el método insertarOrdenado.
    printf("Mostrando array inicial (ordenado de 5 elementos).\n");
    print(a, size);
    insertarOrdenado(a, 5, 9);
    printf("Mostrando array despues de insertar un elemento con 'insertarOrdenado'\n");
    print(a, size+1);

    printf("\n");

    // Probamos el método ordenar, con un array desordenado.
    a[0] = 13;
    a[1] = 15;
    a[2] = 2;
    a[3] = -5;
    a[4] = 10;
    printf("Mostrando array desordenado.\n");
    print(a, size);
    ordenar(a, 5);
    printf("Mostrando array ordenado\n");
    print(a, size+1);

    return 0;
}
