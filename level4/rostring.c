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
*/

#include <unistd.h>
#include <stdlib.h>

// Función para verificar si un carácter es espacio o tab
int is_space (char c)
{
    return (c == ' ' || c == '\t');
}

// Función para escribir una cadena
void putstr (char *str, int len)
{
    write(1, &str, len);
}

int main (int argc, char **argv)
{
    int i;
    int start;
    int end;
    int first;
    char *str;

    i = 0;
    start = 0;
    end = 0;
    first = 1;
    str = NULL;

    if (argc < 2 || !argv[1][0])
    {
        write (1, "\n", 1);
        return (0);
    }
    str = argv[1];

    // Saltar espacios iniciales 
    while (is_space(str[i]))
        i++;
    // Guardar primera palabra 
    start = i;
    while(str[i] && !is_space(str[i]))
        i++;
    end = i;
    // Imprimir las siguientes palabras
    while (str[i])
    {
        // Saltar espacios entre palabras
        while (is_space && is_space(str[i]))
            i++;
        if (str[i] && !is_space(str[i]))
        {
            if (!first)
                write(1, " ", 1);
            first = 0;

            // Imprimir palabra
            int j = i;
            while (str[j] && !is_space(str[j]))
                j++;
            putstr(&str[i], j - i);
            i = j;
        }
    }
    // Imprimir la primera palabra al final (si había más palabras)
    if (!first)
        write(1, " ", 1);
    putstr(&str[start], end - start);
    write (1, '\n', 1);
    return (0);
}



