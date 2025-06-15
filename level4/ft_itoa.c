/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);

"integer to ASCII" o "número entero a string".
*/


/*
Contar cuántos caracteres necesitas:

Usa un bucle que divida nbr por 10 hasta que llegue a 0.

Si nbr es 0, el resultado debe ser "0" (1 carácter + nulo).

Reservar memoria con malloc.

Convertir el número a texto:

Tomar cada dígito: digit = abs(nbr % 10) + '0'.

Guardarlo en la posición correcta.

Agregar el signo negativo si corresponde.

Terminar con '\0'.
*/
#include <stdlib.h>

int ft_count_len (int nbr)
{
    int i = 0;

    if (nbr <= 0)
        i++;
    while (nbr != 0)
    {
        nbr = nbr / 10;
        i++;
    }
    return (i);
}


char	*ft_itoa(int nbr)
{
    int len;
    char *str;
    long n;

    len = ft_count_len(nbr); // cuántos caracteres necesitamos 
    str = malloc(len + 1);   // +1 para '\0'
    n = nbr; // Usamos long para manejar INT_MIN

    int (!str)
        return (NULL);
    str[len] = '\0';
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    } else if
    {
        if (n == 0)
            str[0] = '0'; //caso especial
    }
    //Llenamos desde el final hasta el principio

    while (n > 0)
    {
        str[--len] = (n % 10) + '0'; //último dígito como char
        n /= 10;
    }
    return (str);   
}