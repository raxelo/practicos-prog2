#include <iostream>

/**
 * Ejercicio 2
 *
 * Considere la representación para árbol binario de Naturales de la Figura 1 y la siguiente representación de
 * Lista de Naturales:
 *
 * (a) Utilícelas para implementar las siguientes funciones:
 * I. enOrden: que recibe un árbol a y retorna una lista con los elementos de a ordenados según la
 *      recorrida en orden de a
 * II. preOrden: que recibe un árbol a y retorna una lista con los elementos de a ordenados según la
 *      recorrida en pre orden de a
 * III. postOrden: que recibe un árbol a y retorna una lista con los elementos de a ordenados según la
 *      recorrida en post orden de a
 * IV. esCamino: que recibe un árbol a y una lista l, y retorna TRUE si y sólo si l es un camino, desde la
 *      raíz a un hoja, de a
 * V. caminoMasLargo: que recibe un árbol a y retorna una lista con los elementos del camino más largo
 *      de a (desde la raíz a una hoja). En caso de haber más de un camino de igual longitud a la del
 *      camino más largo, retorna cualquiera de ellos.
 *
 */

// arbol binario
struct nodoAB {
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;


// lista de naturales
struct nodoLista {
    uint elem;
    nodoLista *sig;
};
typedef nodoLista *Lista;


void printArbol(const std::string &prefix, AB arbol, bool isLeft) {
    if (arbol == nullptr) return;
    std::cout << prefix;
    std::cout << (isLeft ? "├───" : "└───");
    std::cout << arbol->elem << std::endl;

    printArbol(prefix + (isLeft ? "│   " : "    "), arbol->izq, true);
    printArbol(prefix + (isLeft ? "│   " : "    "), arbol->der, false);
}

void printArbol(AB arbol) {
    printArbol("", arbol, false);
}

void printLista(Lista lista) {
    while (lista != nullptr) {
        printf("%d, ", lista->elem);
        lista = lista->sig;
    }
    printf("\n");
}

AB crearArbolRandom(int n, int max) {
    if (n == max) return nullptr;
    AB arbol = new nodoAB;
    arbol->elem = rand() % 100;
    arbol->der = crearArbolRandom(n + 1, max);
    arbol->izq = crearArbolRandom(n + 1, max);
    return arbol;
}


void enOrden(AB arbol, Lista &lista, Lista &last) {
    if (arbol == nullptr) return;
    enOrden(arbol->izq, lista, last);

    if (lista == nullptr) {
        lista = new nodoLista;
        lista->elem = arbol->elem;
        lista->sig = nullptr;
        last = lista;
    } else {
        Lista sig = new nodoLista;
        sig->elem = arbol->elem;
        last->sig = sig;
        last = sig;
    }

    enOrden(arbol->der, lista, last);
}

/**
 * (a) I: enOrden
 * Recibe un árbol a y retorna una lista con los elementos de a ordenados según la
 * recorrida en orden de a
 *
 * @param arbol
 * @return lista con los elementos en orden
 */
Lista enOrden(AB arbol) {
    Lista result = nullptr;
    Lista last = nullptr;
    enOrden(arbol, result, last);
    return result;
}

void preOrden(AB arbol, Lista &lista, Lista &last) {
    if (arbol == nullptr) return;

    if (lista == nullptr) {
        lista = new nodoLista;
        lista->elem = arbol->elem;
        lista->sig = nullptr;
        last = lista;
    } else {
        Lista sig = new nodoLista;
        sig->elem = arbol->elem;
        last->sig = sig;
        last = sig;
    }

    preOrden(arbol->izq, lista, last);
    preOrden(arbol->der, lista, last);
}

/**
 * (a) II: preOrden
 * Recibe un árbol a y retorna una lista con los elementos de a ordenados según la
 * recorrida en pre orden de a
 *
 * @param arbol
 * @return lista con los elementos en pre-orden
 */
Lista preOrden(AB arbol) {
    Lista result = nullptr;
    Lista last = nullptr;
    preOrden(arbol, result, last);
    return result;
}

void postOrden(AB arbol, Lista &lista, Lista &last) {
    if (arbol == nullptr) return;

    postOrden(arbol->izq, lista, last);
    postOrden(arbol->der, lista, last);

    if (lista == nullptr) {
        lista = new nodoLista;
        lista->elem = arbol->elem;
        lista->sig = nullptr;
        last = lista;
    } else {
        Lista sig = new nodoLista;
        sig->elem = arbol->elem;
        last->sig = sig;
        last = sig;
    }

}

/**
 * (a) III: postOrden
 * Recibe un árbol a y retorna una lista con los elementos de a ordenados según la
 * recorrida en post orden de a
 * @param arbol
 * @return lista con los elementos en post-orden
 */
Lista postOrden(AB arbol) {
    Lista result = nullptr;
    Lista last = nullptr;
    postOrden(arbol, result, last);
    return result;
}

/**
 * IV: esCamino
 * Que recibe un árbol a y una lista l, y retorna TRUE si y sólo si l es un camino, desde la
 * raíz a un hoja, de a
 * @param lista
 * @param arbol
 * @return true si es camino, false si no lo es.
 */
bool esCamino(Lista lista, AB arbol) {
    if (lista == nullptr) return arbol == nullptr;
    if (lista->elem != arbol->elem) return false;
    return esCamino(lista->sig, arbol->izq) || esCamino(lista->sig, arbol->der);
}

int altura(AB arbol) {
    if (arbol == nullptr) return 0;

    if (arbol->der == nullptr && arbol->izq == nullptr) return 1;

    if (arbol->der == nullptr) return 1 + altura(arbol->izq);
    if (arbol->izq == nullptr) return 1 + altura(arbol->der);

    int alturaIzquierda = altura(arbol->izq);
    int alturaDerecha = altura(arbol->der);
    if (alturaIzquierda > alturaDerecha) return 1 + alturaIzquierda;

    return 1 + alturaDerecha;
}

void caminoMasLargo(AB arbol, Lista &lista, Lista &last) {
    if (arbol == nullptr) return;

    if (lista == nullptr) {
        lista = new nodoLista;
        lista->elem = arbol->elem;
        lista->sig = nullptr;
        last = lista;
    } else {
        Lista next = new nodoLista;
        next->elem = arbol->elem;
        next->sig = nullptr;
        last->sig = next;
        last = next;
    }

    if (altura(arbol->izq) > altura(arbol->der)) {
        caminoMasLargo(arbol->izq, lista, last);
        return;
    }

    return caminoMasLargo(arbol->der, lista, last);
}

/**
 * V: caminoMasLargo
 * Recibe un árbol a y retorna una lista con los elementos del camino más largo
 * de a (desde la raíz a una hoja). En caso de haber más de un camino de igual longitud a la del
 * camino más largo, retorna cualquiera de ellos.
 *
 * @param arbol
 * @return lista con el camino mas largo
 */
Lista caminoMasLargo(AB arbol) {
    Lista resultado = nullptr;
    Lista fin = nullptr;
    caminoMasLargo(arbol, resultado, fin);
    return resultado;
}

AB tree(int value) {
    AB arbol = new nodoAB;
    arbol->elem = value;
    arbol->der = nullptr;
    arbol->izq = nullptr;
    return arbol;
}

Lista agregarAlFinal(Lista lista, int elem) {
    while (lista->sig != nullptr) {
        lista = lista->sig;
    }
    lista->sig = new nodoLista;
    lista->sig->sig = nullptr;
    lista->sig->elem = elem;
}

int main() {
    AB a1 = tree(1);
    AB a2 = tree(2);
    AB a3 = tree(3);
    AB a4 = tree(4);
    AB a5 = tree(5);

    AB a6 = tree(6);
    AB a7 = tree(7);
    a3->izq = a7;
    a3->der = a6;

    a1->der = a2;
    a1->izq = a3;
    a2->der = a4;
    a2->izq = a5;

    a6->izq = tree(22);
    a5->der = tree(23);
    a5->izq = tree(24);
    a5->izq->izq = tree(25);

    printArbol(a1);
    printLista(caminoMasLargo(a1));

    return 0;
}
