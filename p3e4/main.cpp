#include <iostream>

/**
 * Ejercicio 4 Lista doblemente encadenada
 *
 * Una variante de listas encadenadas es la llamada Lista Doblemente Encadenada. En dicha implementación cada elemento
 * de la lista referencia al siguiente elemento y al elemento anterior. La Figura 2 presenta una representación para
 * esta variante.
 *
 * (b) Implementar las siguientes operaciones utilizando la representación presentada en la Figura 2:
 *      I. null: retorna una lista vacía.
 *      II. cons: dados un entero x y una lista l, retorna el resultado de insertar x al principio de l.
 *      III. isEmpty: dada una lista l, verifica si l está vacía.
 *      IV. isElement: dados un entero x y una lista l, verifica si x pertenece a l.
 *      V. removeAll: dados un entero x y una lista l, retorna el resultado de eliminar todas las ocurrencias
 *          de x de l.
 *      VI. insOrd: dados un entero x y una lista l ordenada, retorna el resultado de insertar x en l ordenadamente.
 */

struct nodo_doble {
    int elem;
    nodo_doble *sig;
    nodo_doble *ant;
};
typedef nodo_doble *Lista;

Lista null() {
    Lista resultado = nullptr;
    return resultado;
}

Lista cons(int x, Lista &l) {
    Lista nuevo = new nodo_doble;
    nuevo->ant = nullptr;
    nuevo->sig = l;
    nuevo->elem = x;

    l = nuevo;
    return l;
}

bool isEmpty(Lista l) {
    return l == nullptr;
}

bool isElement(int x, Lista l) {
    while (!isEmpty(l) && l->elem != x) {
        l = l->sig;
    }

    return l != nullptr && l->elem == x;
}

Lista removeAll(int x, Lista l) {
    Lista aux = l;
    while (!isEmpty(aux)) {
        if (aux->elem != x) {
            aux = aux->sig;
            continue;
        }

        if (aux->ant != nullptr) {
            aux->ant->sig = aux->sig;
        }

        if (aux->sig != nullptr) {
            aux->sig->ant = aux->ant;
        }

        Lista previo = aux;
        aux = aux->sig;

        delete previo;
    }

    return l;
}

void insOrd(int x, Lista &l) {
    if (isEmpty(l)) {
        l = new nodo_doble;
        l->sig = nullptr;
        l->ant = nullptr;
        l->elem = x;
        return;
    }

    Lista aux = l;
    Lista ant = nullptr;
    while (aux != nullptr && x > aux->elem) {
        ant = aux;
        aux = aux->sig;
    }

    if (aux == nullptr) {
        Lista nuevo = new nodo_doble;
        nuevo->sig = nullptr;
        nuevo->ant = ant;
        nuevo->elem = x;
        ant->sig = nuevo;
        return;
    }

    Lista nuevo = new nodo_doble;
    nuevo->sig = aux;
    nuevo->ant = aux->ant;
    aux->ant = nuevo;
    nuevo->elem = x;

    if (ant != nullptr) {
        ant->sig = nuevo;
    }
}

void imprimirCadena(Lista lista) {
    while (lista != nullptr) {
        printf("%d, ", lista->elem);
        lista = lista->sig;
    }
    printf("\n");
}

int main() {
    Lista lista = nullptr;

    insOrd(1, lista);
    insOrd(3, lista);
    insOrd(40, lista);
    insOrd(8, lista);
    insOrd(10, lista);

    imprimirCadena(lista);
    return 0;
}
