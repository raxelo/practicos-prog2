#include <iostream>

/**
 * Ejercicio 1
 *
 * (a) ¿Cómo representaría al árbol vacío con dicha representación?
 *
 * (b) Utilice la representación dada para implementar las siguientes operaciones:
 * I. función consArbol: que crea un árbol no vacío a partir de un natural y otros dos árboles.
 * II. función contarElems: que recibe un árbol y retorna la cantidad de elementos que tiene el mismo.
 * III. función altura: que recibe un árbol y retorna la altura del mismo. Si el árbol es vacío su altura es 0.
 * IV. función contarHojas: que recibe un árbol y retorna la cantidad de hojas (nodos cuyos ambos
 *     subárboles son vacíos) del mismo.
 * V. función copiar: que recibe un árbol y crea una copia limpia (que no comparte registros de memoria)
 *    del mismo.
 * VI. procedimiento liberarArbol: que recibe un árbol y elimina del mismo todos los nodos, liberando
 *     la memoria asociada a cada uno de ellos. El árbol se transforma en un árbol vacío.
 *
 * (c) La estructura que devuelve su solución de consArbol: ¿comparte memoria con los parámetros?
 *     En caso afirmativo: ¿qué problemas puede acarrear esto?
 */

struct nodoAB {
    int elem;
    nodoAB *izq, *der;
};
typedef nodoAB *AB;

/**
 * (b) I: consArbol
 * Crea un árbol no vacío a partir de un natural y otros dos árboles.
 *
 * @param elemento el elemento del nodo
 * @param izquierda el arbol de la izquierda
 * @param derecha el arbol de la derecha
 * @return un nuevo arbol
 */
AB consArbol(int elemento, AB izquierda, AB derecha) {
    AB nuevo = new nodoAB;
    nuevo->elem = elemento;
    nuevo->izq = izquierda;
    nuevo->der = derecha;

    return nuevo;
}

/**
 * (b) II: contarElems
 * Recibe un árbol y retorna la cantidad de elementos que tiene el mismo.
 *
 * @param arbol
 * @return cantidad de elementos del arbol
 */
int contarElems(AB arbol) {
    if (arbol == nullptr) return 0;

    if (arbol->izq == nullptr && arbol->der == nullptr) return 1;

    return 1 + contarElems(arbol->izq) + contarElems(arbol->der);
}

/**
 * (b) III: altura
 * Recibe un árbol y retorna la altura del mismo. Si el árbol es vacío su altura es 0.
 *
 * @param arbol
 * @return la altura del arbol
 */
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

/**
 * (b) IV: contarHojas
 * Recibe un árbol y retorna la cantidad de hojas (nodos cuyos ambos
 * subárboles son vacíos) del mismo.
 *
 * @param arbol
 * @return las cantidad de hojas del arbol
 */
int contarHojas(AB arbol) {
    if (arbol == nullptr) return 0;
    if (arbol->der == nullptr && arbol->izq == nullptr) return 1;

    if (arbol->der == nullptr) return contarHojas(arbol->izq);
    if (arbol->izq == nullptr) return contarHojas(arbol->der);

    return contarHojas(arbol->der) + contarHojas(arbol->izq);
}

/**
 * (b) V: copiar
 * Recibe un árbol y crea una copia limpia (que no comparte registros de memoria)
 * del mismo.
 *
 * @param arbol
 * @return una copia limpia
 */
AB copiar(AB arbol) {
    if (arbol == nullptr) return nullptr;

    AB nuevo = new nodoAB;
    nuevo->izq = copiar(arbol->izq);
    nuevo->der = copiar(arbol->der);
    nuevo->elem = arbol->elem;
    return nuevo;
}

/**
 * (b) VI: liberarArbol
 * Recibe un árbol y elimina del mismo todos los nodos, liberando
 * la memoria asociada a cada uno de ellos. El árbol se transforma en un árbol vacío.
 * @param arbol
 */
void liberarArbol(AB arbol) {
    if (arbol == nullptr) return;
    liberarArbol(arbol->der);
    liberarArbol(arbol->izq);
    delete arbol;
}

void printArbol(const std::string &prefix, AB arbol, bool isLeft) {
    if (arbol == nullptr) return;
    std::cout << prefix;
    std::cout << (isLeft ? "├───" : "└───");
    std::cout << arbol->elem << std::endl;

    printArbol(prefix + (isLeft ? "│   " : "    "), arbol->izq, true);
    printArbol(prefix + (isLeft ? "│   " : "    "), arbol->der, false);
}

AB crearArbolRandom(int n, int max) {
    if (n == max) return nullptr;
    AB arbol = new nodoAB;
    arbol->elem = rand();
    arbol->der = crearArbolRandom(n+1, max);
    arbol->izq = crearArbolRandom(n+1, max);
    return arbol;
}

/**
 * Respuesta (c):
 *
 * El método consArbol no crea copia del árbol izquierda o derecha, sino que los utiliza directamente en el
 * árbol nuevo.
 *
 * Esto tiene, como consecuencia, que al llamar métodos que alteren el árbol (por ejemplo liberarArbol) modifique
 * árboles previamente creados. Tambien tiene como consecuencia que al llamar consArbol sin tener cuidado, podemos
 * insertar un nodo AB en varios árboles no relacionados.
 */

int main() {
    AB izquierda = crearArbolRandom(0, 2);
    AB derecha = crearArbolRandom(0, 4);
    AB arbol = new nodoAB;
    arbol->elem = 0;
    arbol->izq = izquierda;
    arbol->der = derecha;

    printArbol("", arbol, false);
    printf("Elementos: %d\n", contarElems(arbol));
    printf("Hojas: %d\n", contarHojas(arbol));
    printf("Altura: %d\n", altura(arbol));
    return 0;
}
