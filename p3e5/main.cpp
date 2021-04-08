#include <iostream>

/** Ejercicio 5 Lista indizada (Manejo explícito de posiciones)
 *
 * Una variante importante de listas son las Listas con manejo explícito de posiciones (a veces llamadas Listas
 * Indizadas). Las operaciones más conocidas de estas listas ya fueron vistas anteriormente en el práctico 1 y
 * en este práctico se quiere implementarlas mediante estructuras pedidas en forma dinámica.
 * En estas listas, se manipulan los elementos mediante posiciones, generalizando la idea de los arreglos
 * para estructuras no acotadas. La posición del primer elemento es la posición 0. Se dice que la posición p
 * está definida si está entre 0 y m -1, siendo m la longitud de la lista. Utilizando la representación de lista
 * doblemente encadenada, implemente las siguientes operaciones:
 *
 * (a) isDefined: dados un natural p y una lista l, retorna verdadero si, y solamente si, existe un elemento en
 * esa posición.
 *
 * (b) insert: dados un entero x, un natural p y una lista l de longitud m, inserta a x en la lista. Si p no esta
 * definida, inserta a x en la posición m. En otro caso, inserta a x en la posición p y desplaza en una
 * posición los elementos que estuvieran en las posiciones siguientes.
 *
 * (c) element: dados un natural p y una lista l, retorna el elemento en la posición p. Tiene como precondición
 * que la posición p esté definida.
 *
 * (d) remove: dados un natural p y una lista l, elimina de la lista el elemento que se encuentra en la posición
 * p. Si la posición no está definida, la operación no tiene efecto. Si la posición está definida, elimina el
 * elemento en dicha posición y desplaza en una posición los elementos que estuvieran en las posiciones
 * posteriores a p (contrae la lista).
 *
 */

struct nodo_doble {
    int elem;
    nodo_doble *sig;
    nodo_doble *ant;
};
typedef nodo_doble *Lista;


bool isDefined(int p, Lista l) {
    if (l == nullptr) return false;

    if (p == 0) return true;

    int i;
    for (i = 0; i < p; i++) {
        l = l->sig;
        if (l == nullptr) break;
    }

    return i == p;
}

void insertarAlFinal(int x, Lista &l) {
    if (l == nullptr) {
        l = new nodo_doble;
        l->sig = nullptr;
        l->ant = nullptr;
        l->elem = x;
        return;
    }

    Lista aux = l;
    while (aux->sig != nullptr) {
        aux = aux->sig;
    }

    Lista nuevo = new nodo_doble;
    nuevo->sig = nullptr;
    nuevo->ant = aux;
    nuevo->elem = x;
    aux->sig = nuevo;
}

void insert(int x, int p, Lista &l) {
    if (!isDefined(p, l)) {
        insertarAlFinal(x, l);
        return;
    }

    Lista nuevo = new nodo_doble;
    nuevo->elem = x;

    Lista aux = l;
    for (int i = 0; i < p; i++) {
        aux = aux->sig;
    }

    if (aux->ant != nullptr) {
        nuevo->ant = aux->ant;
        aux->ant->sig = nuevo;
    } else {
        l = nuevo;
    }

    aux->ant = nuevo;
    nuevo->sig = aux;
}

int element(int p, Lista l) {
    for (int i = 0; i < p; i++) {
        l = l->sig;
    }

    return l->elem;
}

void remove(int p, Lista &l) {
    if (!isDefined(p, l)) return;

    if (p == 0) {
        Lista prev = l;
        l = l->sig;
        delete prev;
        return;
    }

    Lista aux = l;
    for (int i = 0; i < p; i++) {
        aux = aux->sig;
    }

    aux->ant->sig = aux->sig;
    delete aux;
}

void imprimirCadena(Lista lista) {
    while (lista != nullptr) {
        printf("%d, ", lista->elem);
        lista = lista->sig;
    }
    printf("\n");
}

int main() {
    Lista list = nullptr;
    insertarAlFinal(1, list);
    insertarAlFinal(2, list);
    insertarAlFinal(3, list);
    insertarAlFinal(4, list);

    insert(100, 3, list);

    insert(99, 1, list);

    imprimirCadena(list);
    return 0;
}
