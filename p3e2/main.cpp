#include <iostream>

/**
 * Utilizando la representación para Lista Encadenada de Enteros de la Figura 1, implemente las siguientes
 * funciones en forma iterativa y sin usar procedimientos auxiliares. Las soluciones retornadas no deben
 * compartir memoria con los parámetros.
 *
 * (a) take: dado un natural i y una lista l, retorna la lista resultado de tomar los primeros i elementos de l.
 * (b) drop: dado un natural i y una lista l, retorna la lista resultado de eliminar los primeros i elementos de l.
 * (c) mergeSort: dadas dos listas ordenadas l y p, genera una lista intercalando ordenadamente ambas
 *   listas.
 * (d) concat: dadas dos listas l y p, retorna una lista que contiene a los elementos de l y luego a los elementos de
 *   p, en el mismo orden. Comparar con la solución recursiva.
 */

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo *Lista;

/**
 * (a) take: dado un natural i y una lista l, retorna la lista resultado de tomar los primeros i elementos de l.
 */
Lista take(int i, Lista l) {
    Lista resultado = new nodo;
    Lista aux = resultado;

    while (l != nullptr && i > 0) {
        aux->elem = l->elem;
        aux->sig = nullptr;

        i--;
        if (l == nullptr || i <= 0) break;

        aux->sig = new nodo;
        aux = aux->sig;
        l = l->sig;
    }

    return resultado;
}

/**
 * (b) drop: dado un natural i y una lista l, retorna la lista resultado de eliminar los primeros i elementos de l.
 */
Lista drop(int i, Lista l) {
    for (int j = 0; j < i; j++) {
        l = l->sig;
        if (l == nullptr) return nullptr;
    }

    Lista resultado = new nodo;
    Lista aux = resultado;
    while (l != nullptr) {
        aux->elem = l->elem;
        aux->sig = nullptr;
        l = l->sig;

        if (l == nullptr) break;
        aux->sig = new nodo;
        aux = aux->sig;
    }

    return resultado;
}

/**
 * (c) mergeSort: dadas dos listas ordenadas l y p, genera una lista intercalando ordenadamente ambas
 * listas.
 */
Lista mergeSort(Lista l, Lista p) {
    if (l == nullptr && p == nullptr) return nullptr;

    Lista resultado = new nodo;
    Lista aux = resultado;

    while (l != nullptr || p != nullptr) {
        if (l == nullptr) {
            aux->elem = p->elem;
        }

        if (p == nullptr) {
            aux->elem = l->elem;
        }

        if (l != nullptr && p != nullptr) {
            int max = l->elem > p->elem ? l->elem : p->elem;
            int min = max == l->elem ? p->elem : l->elem;

            aux->elem = min;
            aux->sig = new nodo;

            aux = aux->sig;
            aux->elem = max;
        }

        if (l->sig == nullptr && p->sig == nullptr) {
            aux->sig = nullptr;
        } else {
            aux->sig = new nodo;
            aux = aux->sig;
        }

        if (l != nullptr) l = l->sig;
        if (p != nullptr) p = p->sig;
    }

    return resultado;
}

/**
 * (d) concat: dadas dos listas l y p, retorna una lista que contiene a los elementos de l y luego a los elementos de
 *   p, en el mismo orden. Comparar con la solución recursiva.
 */
Lista concat(Lista l, Lista p) {
    if (l == nullptr && p == nullptr) return nullptr;

    Lista resultado = new nodo;
    Lista aux = resultado;

    while (l != nullptr) {
        aux->elem = l->elem;
        aux->sig = nullptr;
        l = l->sig;

        if (l != nullptr || p != nullptr) {
            aux->sig = new nodo;
            aux = aux->sig;
        }
    }

    while (p != nullptr) {
        aux->elem = p->elem;
        aux->sig = nullptr;
        p = p->sig;

        if (p != nullptr) {
            aux->sig = new nodo;
            aux = aux->sig;
        }
    }

    return resultado;
}

int main() {
    return 0;
}
