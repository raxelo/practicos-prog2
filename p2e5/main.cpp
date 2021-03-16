#include <iostream>

/**
 * Ejercicio 5 Torres de Hanoi
 *
 * Escenario: existen tres cilindros verticales, A, B y C, en los que es posible insertar discos. En el cilindro
 * A hay n discos todos de diferente tamaño, colocados en orden de tamaño con el más chico arriba. Los otros dos
 * cilindros están vacíos. El problema es pasar la torre de discos al cilindro C usando como único movimiento
 * elemental el cambio de un disco de un cilindro a otro cualquiera, sin que en ningún momento un disco vaya a
 * colocarse encima de otro más chico que él. La Figura 2 presenta los estados inicial y final de este problema
 * para 3 discos.
 *
 * Implememte un algoritmo para imprimir las secuencias de movimientos elementales que resuelvan el problema de
 * las torres de Hanoi, de cualquier tamaño.
 *
 * Los movimientos elementales son de la forma: MOVER DISCO i DEL cilindro x AL cilindro y.
 */

void mover(int num, int from, int to) {
    printf("MOVER DISCO %d DEL cilindro %d AL cilindro %d\n", num, from, to);
}

/**
 * Devuelve un número del 1 al 3 distinto de start y end.
 */
int getCilindroAuxiliar(int start, int end) {
    if (start != 1 && end != 1) {
        return 1;
    } else if (start != 2 && end != 2) {
        return 2;
    }

    return 3;
}

/**
 * Me llevó unas horas entender esto hasta que ví este video
 * https://youtu.be/rf6uf3jNjbo
 *
 * La magia de este algoritmo es que para escribirlo asumís
 * que se cumple, jugás con la inducción y sale solo.
 */
void hanoi(int n, int start, int end) {
    if (n == 1) {
        mover(n, start, end);
        return;
    }

    // Como tenemos tres cilindros, el cilindro auxiliar es
    // aquel que no es ni el "start" ni el "end"
    int cilindroAux = getCilindroAuxiliar(start, end);

    // Por hipótesis inductiva, puedo asumir que hanoi funciona para n-1.
    // por tanto podemos resolver el problema moviendo todos los anteriores
    // discos al cilindro auxiliar.
    hanoi(n - 1, start, cilindroAux);

    // Ahora que tenemos todos los discos anteriores en el cilindro auxiliar,
    // procedemos a mover el ultimo disco (el mas grande) del cilindro start
    // al cilindro end.
    mover(n, start, end);

    // para terminar ponemos los discos que dejamos en el auxiliar encima de la base.
    hanoi(n - 1, cilindroAux, end);
}

int main() {
    hanoi(3, 1, 3);
    return 0;
}
