/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    int n;
    int first;
    int i;

    n = atoi(argv[1]);
    first = 1;
    i = 2;

    if (argc == 2)
    {
        while(n > 1)
        {
            if (n % i == 0)
            {
                if (!first)
                    printf("*");
                printf("%d", i);
                first = 0; //marcamos que ya imprimimos el primer número
                n /= i; // divide n entre i y guarda el resultado de nuevo en n
            }
            else 
            {
                i++;
            }
        }
        printf("\n");
        return (0);
    }
    printf("\n");
    return (0);
}