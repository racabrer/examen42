/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

Pasos que debe seguir tu función
1. Contar cuántas palabras hay en la cadena.

2. Reservar memoria para el array de char * (con malloc), con espacio suficiente para todas las palabras +1 para el NULL final.

3. Recorrer la cadena, ir copiando palabra por palabra:

    - Saltar los separadores (' ', '\n', '\t')

    - Guardar inicio y fin de cada palabra

    - Reservar memoria para cada palabra

    - Copiar los caracteres uno por uno

4. Terminar el array con un puntero NULL

*/
#include <unistd.h>
#include <stdlib.h>

int count_words (char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if (str[i] != '\0')
            count++;
        while (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
            i++;
    }
    return (count);
}

void copy_words (char *tab, char *str, int start, int end)
{
    int j;

    j = 0;
    while (start < end)
        tab[j++] = str[start++];
        tab[j] = '\0';
}

int find_next_word(char *str, int *start, int *end)
{
    int i;

    i = *end; // Comienza desde el valor actual de "end"
    // i se inicializa con *end, que representa la posición actual en el string
    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
        i++;
    *start = i; // Marca el inicio de la palabra
    //  Guarda la posición donde empieza la siguiente palabra en *start
    while (str[i] != '\0' && str[i] != ' ' && str[i]  != '\t' && str[i] != '\n')
        *end = i; // Guarda el índice i en *end, indicando la última posición de la palabra 
    return (*start < *end); // Devuelve 1 si encontró una palabra, y 0 si no la hay
}

int ft_fill_words (char **tab, char *str)
{
    int i;
    int word;
    int start;
    int end;

    i = 0;
    word = 0;
    start = 0;
    end = 0;

    while (find_next_word(str, &start, &end)) // Mientras haya palabras, sigue procesándolas
    {
        tab[word] = malloc ((end - start + 1) * sizeof(char)); // Reserva memoria para almacenar la palabra extraída
        if (tab[word] == NULL)
        {
            i = 0;
            while (i < word)
                free(tab[i++]);
            free (tab);
            return (0);
        }
        copy_words(tab[word], str, start, end); // Copia la palabra desde str a tab[word]
        word++; // Avanza al siguiente espacio en tab para la próxima palabra
    }
    tab[word] == NULL; // Coloca NULL como marcador final en tab para indicar el final del array de palabras.
    return (1);
}

char    **ft_split(char *str)
{
    char **out;
    int size;

    size = count_words;
    out = malloc ((sizeof(char *) * (size + 1)));
    if (!out)
        return (NULL);
    if (!ft_fill_words(str, out))
    {
        free(out);
        return (NULL);
    }
    return (out);
}