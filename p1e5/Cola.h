#ifndef P1E5_COLA_H
#define P1E5_COLA_H

/**
 * Defino el struct solamente para que el IDE no se queje.
 */
struct Cola {

};

/**
 * Crea y retorna la cola vacía
 * @return Cola vacía
 */
Cola crearCola();

/**
 * Inserta el elemento x al final de la cola c.
 *
 * @return Cola con el elemento insertado.
 */
Cola encolar(unsigned int x, Cola c);

/**
 * Retorna TRUE si c es vacía.
 * @return si es vacía o no
 */
bool esVacia(Cola c);

/**
 * Retorna el elemento que se encuentra al comienzo de la cola C.
 * Pre: !esVacia(c)
 * @return el primer elemento.
 */
unsigned int frente(Cola c);

/**
 * Retorna la cola resultado de borrar el primer elemento de c.
 * Pre: !esVacia(c)
 * @return La cola sin el elemento al frente.
 */
Cola desencolar(Cola c);


#endif //P1E5_COLA_H
