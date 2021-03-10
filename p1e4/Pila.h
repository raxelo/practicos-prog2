#ifndef P1E4_PILA_H
#define P1E4_PILA_H

/**
 * Defino el struct solamente para que el IDE no se queje.
 */
struct Pila {
};

/**
 * Crea la pila vacía
 *
 * @return Pila vacía
 */
Pila crearPila();

/**
 * Verifica si la Pila p está vacía
 *
 * @param p una pila
 * @return si está vacía o no
 */
bool esVacia(Pila p);

/**
 * Inserta el elemento x en la cima de la Pila p.
 * x queda como el último elemento apilado
 *
 * @param x el elemento
 * @param p la pila
 * @return una nueva pila con el elemento apilado.
 */
Pila apilar(int x, Pila p);

/**
 * Retorna el elemento de la cima de la Pila p
 * (último elemento apilado)
 *
 * @param p la pila
 * @return el elemento en la cima
 */
int cima(Pila p);

/**
 * Retorna la Pila p sin el elemento de la cima (último elemento apilado)
 *
 * @param p la pila
 * @return una nueva pila sin el elemento de la cima.
 */
Pila desapilar(Pila p);


#endif //P1E4_PILA_H
