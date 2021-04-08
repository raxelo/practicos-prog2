#include <iostream>

/** Ejercicio 6 Lista indizada (Manejo implícito de posiciones)
 *
 * En las Listas con manipulación de elementos por posiciones, éstas se pueden manejar de forma explícita o
 * implícita. En el ejercicio anterior el manejo es explícito. Veremos en este ejercicio el manejo implícito. Una
 * posible implementación para estas listas consiste en, además de la referencia al inicio de la estructura,
 * mantener otra posición (llamémosle posición actual). El tipo lista que se presenta de la Figura 3 implementa
 * esta variante. Usando esta representación implemente las siguientes operaciones:
 *
 *
 * (a) null: crea una lista vacía
 *
 * (b) start: dada una lista l no vacía, coloca la posición actual al inicio de l.
 *
 * (c) next: dada una lista l no vacía, mueve la posición actual al siguiente nodo (elemento). En caso de
 * que la posición actual sea el final de la lista, coloca la posición actual al inicio de la lista (tiene un
 * comportamiento circular).
 *
 * (d) insert: dados un entero x y una lista l, inserta el elemento x luego de la posición actual en la lista. La
 * posición actual pasa a ser el elemento (nodo) recién insertado. Si la lista l está vacía, el resultado es la
 * lista unitaria que contiene a x, siendo este elemento la posición actual en la lista resultado.
 *
 * (e) element: dada una lista l no vacía, retorna el elemento en la posición actual de l.
 */

// Figura 3: Lista indizada.
struct nodo {
    int elem;
    nodo *sig;
};
struct cabezal {
    nodo *primero;
    nodo *actual;
};
typedef cabezal *Lista;

Lista null() {
    Lista lista = new cabezal;
    lista->primero = nullptr;
    lista->actual = nullptr;
    return lista;
}

void start(Lista lista) {
    lista->actual = lista->primero;
}

void next(Lista lista) {
    if (lista->actual->sig == nullptr) {
        lista->actual = lista->primero;
        return;
    }

    lista->actual = lista->actual->sig;
}

void insert(int x, Lista lista) {
    nodo *actual = lista->actual;
    lista->actual = new nodo;
    lista->actual->elem = x;

    if (lista->primero == nullptr) {
        lista->primero = lista->actual;
    }

    if (actual != nullptr) {
        actual->sig = lista->actual;
    }
}

int element(Lista lista) {
    return lista->actual->elem;
}

void imprimirLista(Lista lista) {
    nodo *aux = lista->primero;
    while (aux != nullptr) {
        printf("%d, ", aux->elem);
        aux = aux->sig;
    }
    printf("\n");
}

int main() {
    Lista lista = null();
    insert(1, lista);
    insert(2, lista);
    insert(3, lista);
    insert(4, lista);
    insert(5, lista);

    imprimirLista(lista);

    return 0;
}
