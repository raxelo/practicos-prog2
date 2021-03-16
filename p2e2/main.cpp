#include <iostream>

/**
 * Ejercicio 2 Es Palindrome
 *
 * Implemente un algoritmo recursivo que determina si un string es palíndrome. El string está representado en
 * un arreglo.
 *
 */

/**
 * Esta se me ocurrió sin mirar ejemplos,
 * pensé en recorrer desde el fin hasta la mitad de la palabra.
 *
 * Necesita como parámetros la longitud de palabra, y la longitud -1.
 * No es tan lindo como la solución 2.
 *
 * pos = length - 1
 * length = longitud de la palabra
 */
bool isPalindrome(char * word, int pos, int length) {
    if (pos < length / 2) return true; // pasamos la mitad de la palabra bien, es palíndrome.

    if (word[pos] != word[length - pos - 1]) return false;
    return isPalindrome(word, pos - 1, length);
}

/**
 * Esta solución la hice después de mirar ejemplos.
 * Es hermosa.
 *
 * Normalmente:
 * end = length - 1
 * start = 0
 */
bool isPalindrome2(char * word, int start, int end) {
    if (start >= end) return true;
    if (word[start] != word[end]) return false;

    return isPalindrome2(word, start+1, end-1);
}

int main() {
    char * palabra = new char[100];
    palabra[0] = 'u';
    palabra[1] = 'w';
    palabra[2] = 'u';

    printf(isPalindrome2(palabra, 0, 2) ? "Es palindrome" : "No es palindrome");

    return 0;
}
