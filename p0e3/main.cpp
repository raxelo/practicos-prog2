#include <iostream>

/** Ejercicio 3 Ocurrencias
 *
 * Se quiere implementar una función que cuente la cantidad de veces que una letra aparece en una frase.
 *   La frase se representa como un arreglo de caracteres, y dado que se conoce que el largo máximo de una
 *   frase es de 100 caracteres, la frase se implementa como char frase[100] .
 *
 * Usando esta representación escriba una función Ocurrencias que recibe una frase, un natural llamado
 *   largo que representa el número de caracteres en la frase, y el caracter a buscar (almacenado en la variable
 *   letra), y devuelve el número de ocurrencias del carácter letra en el arreglo frase.
 */

int ocurrencias(char frase[], int largo, char letra) {
    int ocurrencias = 0;
    for (int i = 0; i < largo; i++) {
        if (frase[i] != letra) continue;
        ocurrencias++;
    }

    return ocurrencias;
}

int main() {
    char input[10];
    std::cerr<<5;
    scanf("%s", input);
    printf("%i", ocurrencias(input, 10, 'e'));
    return 0;
}
