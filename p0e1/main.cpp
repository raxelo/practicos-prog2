#include <iostream>

/**
 * Ejercicio 1 Promedio clase
 *
 * Suponga que a los estudiantes de programación 2 se les dice que su calificación final será el promedio de
 *   las cuatro calificaciones más altas de entre las cinco que hayan obtenido en el curso
 *
 * (a) Escribir una función llamada PromClase con cinco parámetros de entrada (las calificaciones obtenidas)
 *   y un parámetro de salida (la calificación promedio), que realice dicho cálculo
 *
 * (b) Escribir un programa principal (main()) que permita ejecutar la función PromClase. Dicho programa
 *   deberá leer de la entrada estándar (teclado) 5 calificaciones, invocar al procedimiento PromClase con
 *   dichos parámetros, y finalmente mostrar en la salida estándar (pantalla) el resultado.
 *
 */

double PromClase(int cal1, int cal2, int cal3, int cal4, int cal5) {
    int calificaciones[5] = {cal1, cal2, cal3, cal4, cal5};
    int aux;

    /**
     * Ordenamos el arreglo de calificacione de manera descendiente.
     *
     * Como necesitamos 4 de 5 calificaciones, ordenar el arreglo entero es equivalente
     * a conseguir las 4 calificaciones más altas.
     */
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (calificaciones[i] < calificaciones[j]) {
                aux = calificaciones[j];
                calificaciones[j] = calificaciones[i];
                calificaciones[i] = aux;
            }
        }
    }

    double promedio = 0;
    for (int i = 0; i < 4; i++) {
        promedio += calificaciones[i];
    }

    return promedio / 4;
}

int main() {
    int cal1;
    int cal2;
    int cal3;
    int cal4;
    int cal5;

    scanf("%d", &cal1);
    scanf("%d", &cal2);
    scanf("%d", &cal3);
    scanf("%d", &cal4);
    scanf("%d", &cal5);
    printf("%lf", PromClase(cal1, cal2, cal3, cal4, cal5));
    return 0;
}
