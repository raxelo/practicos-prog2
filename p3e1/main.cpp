#include <cstdio>

/**
 * Ejercicio 1 Lista simple
 *
 * (a) Utilizando la representación de la Figura 1, implemente las siguientes funciones o procedimientos en
 * forma iterativa y sin usar procedimientos auxiliares. En el caso de inserciones o eliminaciones se
 * debe modificar los parámetros de entrada y compartir memoria con los mismos.
 *
 * I. last: dada una lista no vacía, retorna su último elemento
 * II. average: dada una lista no vacía, retorna el promedio de sus elementos.
 * III. insOrd: dados un entero x y una lista l ordenada: inserta x en l ordenadamente. Comparar con la
 *      solución recursiva.
 * IV. snoc: dados un entero x y una lista l, inserta x al final de l.
 * V. removeAll: dados un entero x y una lista l, elimina a x de l.
 * VI. isIncluded: dadas dos listas l y p, verifica si l está incluida en p. Una lista l1 está incluida en l2 si
 * y sólo sí existen dos listas, l3 y l4, tal que cumplen que l2 = l3l1l4. Tenga en cuenta que las listas li,
 * con i ∈ {1, ..., 4} pueden ser vacías.
 */

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo *Lista;

int last(Lista lista) {
    while (lista->sig != nullptr) {
        lista = lista->sig;
    }
    return lista->elem;
}

double average(Lista lista) {
    double sum = lista->elem;
    int amount = 1;
    while (lista->sig != nullptr) {
        lista = lista->sig;
        sum += lista->elem;
        amount++;
    }

    return sum / amount;
}

void insOrd(Lista &lista, int x) {
    Lista newNode = new nodo;
    newNode->elem = x;

    if (lista == nullptr || lista->elem > x) {
        newNode->sig = lista;
        lista = newNode;
        return;
    }

    Lista copy = lista;
    while (copy->sig != nullptr && copy->sig->elem < x) {
        copy = copy->sig;
    }

    newNode->sig = copy->sig;
    copy->sig = newNode;
}

void snoc(Lista &lista, int x) {
    Lista newNode = new nodo;
    newNode->sig = nullptr;
    newNode->elem = x;

    if (lista == nullptr) {
        lista = newNode;
        return;
    }

    Lista copy = lista;
    while (copy->sig != nullptr) {
        copy = copy->sig;
    }

    copy->sig = newNode;
}

void removeAll(Lista &lista, int x) {
    if (lista == nullptr) return;

    Lista aux = lista;
    Lista prev = nullptr;
    while (aux != nullptr) {
        Lista sig = aux->sig;
        if (aux->elem == x) {
            if (prev == nullptr) {
                lista = lista->sig;
                delete aux;
            } else {
                prev->sig = prev->sig->sig;
                delete aux;
            }
        } else {
            prev = aux;
        }
        aux = sig;
    }
}

bool startsWith(Lista lista, Lista subLista) {
    if (subLista == nullptr) return true;
    if (lista == nullptr) return false;

    return (lista->elem == subLista->elem && startsWith(lista->sig, subLista->sig));
}

bool isIncluded(Lista subLista, Lista lista) {
    if (subLista == nullptr) return true;
    if (lista == nullptr) return false;

    return (subLista->elem == lista->elem && startsWith(lista->sig, subLista->sig)) || isIncluded(subLista, lista->sig);
}

void printLista(Lista lista) {
    while (lista != nullptr) {
        printf("%d, ", lista->elem);
        lista = lista->sig;
    }
    printf("\n");
}

int main() {
    return 0;
}
