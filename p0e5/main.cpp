#include <iostream>

/** Ejercicio 5 Ordenar arreglo
 *
 * Escriba un procedimiento que recibe un arreglo de enteros y devuelve un nuevo arreglo que contiene a los
 *   elementos del primero en orden ascendente. Indique qué algoritmos de ordenación utiliza.
 *
 */

void sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] < array[j]) continue;

            int aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    int size;
    scanf("%d", &size);

    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Array no ordenado: ");
    printArray(array, size);

    sort(array, size);

    printf("\nArray ordenado: ");
    printArray(array, size);

    return 0;
}
