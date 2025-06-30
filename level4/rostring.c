/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

1. Verificar que hay al menos un argumento.
2. Saltar espacios iniciales.
3. Guardar la primera palabra.
4. Imprimir el resto de palabras.
5. Imprimir la primera palabra al final.
6. Terminar con \n.

1. Comprobar argumentos
    Si no hay exactamente un argumento, escribe solo un salto de línea (\n) y termina.
2. Saltar espacios iniciales
    Ignora todos los espacios (' ') y tabulaciones ('\t') al inicio de la cadena.
3. Detectar la primera palabra
    Guarda los índices start y end de la primera palabra (la que hay que mover al final).
    Avanza el índice para buscar otras palabras.
4. Recorrer el resto de la cadena
    Por cada palabra que encuentres (después de la primera):
    Sáltate los espacios/tabs entre palabras.
    Encuentra el inicio y el final de la siguiente palabra.
    Imprímela con un espacio antes si ya imprimiste alguna.
5. Imprimir la primera palabra al final
    Si se imprimieron otras palabras antes, añade un espacio.
    Luego imprime la palabra guardada en el paso 3.
6. Terminar con salto de línea
    Siempre imprime un \n al final. 
*/
#include <unistd.h>
#include <stdlib.h>

// Verifica si un carácter es espacio o tabulación
int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

// Escribe una cadena de longitud len
void putstr(char *str, int len)
{
    write(1, str, len);
}

int main(int argc, char **argv)
{
    int i = 0;
    int start = 0;
    int end = 0;
    int first = 1;
    char *str;

    if (argc < 2 || !argv[1][0])
    {
        write(1, "\n", 1);
        return (0);
    }

    str = argv[1];

    // Saltar espacios iniciales
    while (is_space(str[i]))
        i++;

    // Guardar inicio y fin de la primera palabra
    start = i;
    while (str[i] && !is_space(str[i]))
        i++;
    end = i;

    // Imprimir las siguientes palabras
    while (str[i])
    {
        // Saltar espacios entre palabras
        while (is_space(str[i]))
            i++;
        if (str[i] && !is_space(str[i]))
        {
            if (!first)
                write(1, " ", 1);
            first = 0;

            int j = i;
            while (str[j] && !is_space(str[j]))
                j++;
            putstr(&str[i], j - i);
            i = j;
        }
    }

    // Imprimir la primera palabra al final
    if (!first)
        write(1, " ", 1);
    putstr(&str[start], end - start);
    write(1, "\n", 1);
    return 0;
}



