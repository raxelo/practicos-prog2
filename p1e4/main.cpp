#include "Pila.h"
#include "Cola.h"
#include "Lista.h"

/**
 * Ejercicio 4 Combinación de TADs
 * Utilizando los TADs Lista, Pila y Cola de los ejercicios anteriores, implemente las siguientes operaciones.
 *
 * (a) invertirCola que dada una cola c, retorne la cola c invertida.
 * (b) invertirPila que dada una pila p, retorne la pila p invertida.
 * (c) removerDetrasCola que dado una cola c y un elemento x, remueve todos los elementos que se encuentran
 *   detrás de x en la cola (mas nuevos que x).
 * (d) removerDebajoPila que dado una pila p y un elemento x, remueve todos los elementos que se encuentran
 *   debajo de x en la pila (mas antiguos que x)
 * (e) ordenarPila que dada una pila p retorna una nueva pila con los elementos de p ordenados de menor
 *   a mayor, con el elemento menor en el tope de la pila.
 *
 */

/**
 * (a) invertirCola
 *
 * Devuelve la cola c, invertida.
 *
 * @param c la cola
 * @return la cola invertida
 */
Cola invertirCola(Cola c) {
    if (esVacia(c)) return crearCola();
    Cola copia = c;

    Cola resultado = resultado;
    Pila pila = crearPila();

    while (!esVacia(copia)) {
        pila = apilar(frente(copia), pila);
        copia = desencolar(copia);
    }

    while (!esVacia(pila)) {
        resultado = encolar(cima(pila), resultado);
        pila = desapilar(pila);
    }

    return resultado;
}

/**
 * (b) invertirPila
 *
 * Retorna la pila p, invertida
 *
 * @param p la pila
 * @return la pila invertida
 */
Pila invertirPila(Pila p) {
    Pila copia = p;
    Pila resultado = crearPila();
    while (!esVacia(copia)) {
        apilar(cima(copia), resultado);
        desapilar(copia);
    }

    return resultado;
}

/**
 * (c) removerDetrasCola
 *
 * Dado una cola c y un elemento x, remueve todos los elementos que se encuentran
 * detrás de x en la cola (mas nuevos que x)
 *
 * @param c la cola
 * @param x el elemento
 */
void removerDetrasCola(Cola c, int x) {
    Cola aux = crearCola();

    while (!esVacia(c)) {
        int num = frente(c);
        aux = encolar(num, aux);

        c = desencolar(c);
        if (num == x) break;
    }

    while (!esVacia(c)) {
        c = desencolar(c);
    }

    while (!esVacia(aux)) {
        c = encolar(frente(aux), c);
        aux = desencolar(aux);
    }
}

/**
 * (d) removerDebajoPila
 *
 * Dado una pila p y un elemento x, remueve todos los elementos que se encuentran
 *   debajo de x en la pila (mas antiguos que x)
 *
 * @param p la pila
 * @param x el elemento
 */
void removerDebajoPila(Pila p, int x) {
    if (esVacia(p)) return;

    Lista lista = crearLista();
    while (!esVacia(p)) {
        int num = cima(p);
        insertarFinal(num, lista);

        p = desapilar(p);
        if (num == x) break;
    }

    while (!esVacia(p)) {
        p = desapilar(p);
    }

    for (int i = 0; i < largo(lista); i++) {
        int elem = obtener(i, lista);
        p = apilar(elem, p);
    }
}

/**
 * (e) ordenarListaAscendente <método auxiliar>
 *
 * Ordena una lista.
 * El primer elemento (indice 0) es el menor.
 *
 * @param l la lista
 */
void ordenarListaAscendente(Lista l) {
    int size = largo(l);
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int valorI = obtener(i, l);
            int valorJ = obtener(j, l);
            if (valorI < valorJ) continue;

            eliminar(i, l);
            insertar(i, valorJ, l);

            eliminar(j, l);
            insertar(j, valorI, l);
        }
    }
}

/**
 * (e) ordenarPila
 *
 * Dada una pila, retorna una nueva pila con sus elementos ordenados.
 * Los elementos deben estar ordenados de menor a mayor, siendo el mayor
 * el tope de la pila.
 *
 * @param p la pila
 * @return la pila ordenada
 */
Pila ordenarPila(Pila p) {
    Pila resultado = p;
    Lista lista = crearLista();

    while (!esVacia(resultado)) {
        int valor = cima(resultado);
        insertarFinal(valor, lista);
        desapilar(resultado);
    }

    ordenarListaAscendente(lista);
    resultado = crearPila();
    for (int i = 0; i < largo(lista); i++) {
        int valor = obtener(i, lista);
        apilar(valor, resultado);
    }
}

int main() {
    return 0;
}
