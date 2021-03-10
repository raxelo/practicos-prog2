#ifndef P1E3_LISTA_H
#define P1E3_LISTA_H


/**
 * Defino el struct solamente para que el IDE no se queje.
 */
struct Lista {

};

/**
 * Crea la lista vacía
 * @return lista vacía
 */
Lista crearLista();

/**
 * Verifica si la lista está vacía
 *
 * @param l
 * @return si la lista está vacía o no
 */
bool esVacia(Lista l);

/**
 * Dado un natural p, retorna TRUE si y solo si la lista está definida
 * en la posición p, considerando las posiciones a partir de 1
 *
 * @param p posición para verificar si la lista está definida
 * @param l la lista
 * @return si está definida o no
 */
bool estaDefinida(unsigned int p, Lista l);

/**
 * Inserta un elemento x en la lista, en una posición p dada.
 * Si la lista tiene longitud mayor a p, los elementos que le siguen
 * son desplazados.
 * Si la lista tiene una longitud menor a p, inserta el elemento al
 * final de la lista.
 *
 * Pre: p > 0
 *
 * @param x elemento a insertar
 * @param p posición donde se desea insertar el elemento
 * @param l la lista
 * @return la nueva lista con el elemento insertado
 */
Lista insertar(unsigned int x, unsigned int p, Lista l);

/**
 * Retorna el elemento en la posición p de l
 *
 * Pre: estaDefinida(p, l)
 *
 * @param p la posición
 * @param l la lista
 * @return el elemento
 */
unsigned int obtener(unsigned int p, Lista l);

/**
 * Elimina de la lista el elemento en la posicion p.
 * Si la posición no está definida, la operación no tiene efecto.
 * Si la posición está definida, elimina el elemento en esa posición
 * y desplaza todos los elementos que le siguen hacia atrás.
 *
 * @param p la posición
 * @param l la lista
 * @return la nueva lista
 */
Lista eliminar(unsigned int p, Lista l);

#endif //P1E3_LISTA_H
