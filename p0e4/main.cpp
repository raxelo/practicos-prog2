#include <iostream>

/**
 * Ejercicio 4
 *
 * Considere ahora que la frase se representa como un arreglo de caracteres implementado como char *frase
 *
 * (a) ¿Qué diferencias hay entre esta representación y la que utilizó en el Ejercicio 3?
 * (b) Escriba una función EsPalindrome que recibe una frase representada como un puntero a caracter y
 *  devuelve TRUE si la misma es un palíndrome, FALSE en otro caso.
 *
 *
 */

/**
 * Respuesta A:
 *
 * Al representar una frase como un arreglo de caracteres implementado con char * frase,
 * podemos instanciarlo con un tamaño arbitrario dado en momento de ejecución.
 * Además, la memoria del arreglo será reservada al momento de instanciarlo.
 *
 * En cambio, al representar una frase como lo hicimos en el ejercicio 3, el tamaño del
 * array es definido en tiempo de compilación.
 *
 */

bool esPalindromo(char * frase, int size) {
    bool esPalindromo = true;
    for (int i = 0; i < size / 2; i++) {
        esPalindromo = frase[i] == frase[size - i - 1];
        if (!esPalindromo) break;
    }

    return esPalindromo;
}

int main() {
    int size;
    scanf("%d", &size);
    char * frase = new char[size];

    printf("\n");
    scanf("%s", frase);

    printf(esPalindromo(frase, size) ? "Es palindrome!" : "No es palindrome 😢");
    return 0;
}
