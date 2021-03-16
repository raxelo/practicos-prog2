#include <iostream>

/**
 * Ejercicio 3 Rayuela
 *
 * En una hilera de una calle con adoquines unos niños juegan a la rayuela. Para esto numeran los adoquines
 * como se indica en la Figura 1 (VER PDF 👁👄👁). Los movimientos permitidos del juego son:
 *
 * - Al principio del juego los niños se ubican en el adoquín 0.
 * - De un adoquín numerado i se puede saltar al adoquín numerado i + 1.
 * - De un adoquín numerado i se puede saltar al adoquín numerado i + 2 (sin pasar por el adoquín i + 1).
 *
 * Implemente un algoritmo recursivo que calcule el número de caminos posibles para alcanzar un adoquín
 * objetivo numerado con n (mayor que cero). Asuma que la cantidad de caminos para llegar al adoquin 0 es 1.
 * Por ejemplo, el número de caminos posibles para n=3 es 3 y son los siguientes: (0,1,2,3), (0,2,3) y (0,1,3).
 *
 * Calcule la cantidad de caminos para n desde 1 hasta 10.
 *
 */

/**
 * rayuela(1) = 1
 * rayuela(2) = 2
 * rayuela(n) = rayuela(n-1) + rayuela(n-2)
 *
 * Esto me tomó un par de horas visualizar en paint.
 * La cantidad de caminos en N=1 es 1
 * La cantidad de caminos en N=2 es 2
 *
 * La cantidad de caminos en N > 2 es la suma de:
 *    la cantidad de caminos hasta la posicion N-1
 *  + la cantidad de caminos hasta la posicion N-2
 *
 *  Porque llegado a una posicion N, solo podemos l;legar hasta ahí
 *  saltando desde la anterior (N-1), o la anterior de la anterior (N-2).
 */
int rayuela(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    return rayuela(n-1) + rayuela(n-2);
}

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("La rayuela de %d es %d\n", i, rayuela(i));
    }
    return 0;
}
