/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        const char *s1 = av[1];
        const char *s2 = av[2];
        int len = 0, i = 0;

        // Calcular la longitud de s1
        while (s1[len])
            len++;

        // Comprobar si todos los caracteres de s1 están en s2
        while (i < len && *s2)
        {
            // Si el carácter de s1 coincide con el de s2, avanzar en ambos
            if (s1[i] == *s2++)
                i++;
        }

        // Si todos los caracteres de s1 se han encontrado en s2, imprimir s1
        if (i == len)
            write(1, s1, len);
    }

    // Imprimir salto de línea al final, independientemente del resultado
    write(1, "\n", 1);

    return (0);
}
