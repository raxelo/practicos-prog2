#include <iostream>

/** Ejercicio 3
 *
 * (a) Utilizando la representación para Lista Encadenada de Enteros de la Figura 1, implemente los siguientes procedimientos de forma recursiva.
 * I. insOrd: dados un entero x y una lista l ordenada, inserta a x en l ordenadamente.
 * II. snoc: dados un entero x y una lista l, inserta a x al final de l.
 * III. removeAll: dados un entero x y una lista l, elimina a x de l.
 *
 */

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo *Lista;

void insOrd(int x, Lista &l) {
    if (l == nullptr) {
        l = new nodo;
        l->elem = x;
        l->sig = nullptr;
        return;
    }
    if (x <= l->elem) {
        Lista nuevo = new nodo;
        nuevo->elem = x;
        nuevo->sig = l;
        l = nuevo;
        return;
    }

    insOrd(x, l->sig);
}

void snoc(int x, Lista &l) {
    if (l == nullptr) {
        l = new nodo;
        l->elem = x;
        l->sig = nullptr;
        return;
    }

    snoc(x, l->sig);
}

void removeAll(int x, Lista &l) {
    if (l == nullptr) return;

    if (l->elem == x) {
        l = l->sig;
        removeAll(x, l);
        return;
    }

    removeAll(x, l->sig);
}

void printLista(Lista lista) {
    while (lista != nullptr) {
        printf("%d, ", lista->elem);
        lista = lista->sig;
    }
    printf("\n");
}

int main() {
    Lista lista = new nodo;
    lista->elem = 3;

    snoc(2, lista);
    snoc(4, lista);
    snoc(5, lista);
    snoc(6, lista);

    snoc(3, lista);
    snoc(3, lista);

    printLista(lista);

    removeAll(3, lista);
    printLista(lista);

    return 0;
}
