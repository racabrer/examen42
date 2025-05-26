/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$

Objetivo de la función. Obteber el Máximo Común Divisor de dos números, 
que es el número más grande que divide ambos sin dejar resto.
*/
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int number1;
	int number2;

	number1 = atoi(argv[1]);
	number2 = atoi(argv[2]);
	if (argc == 3)
	{
		while (number1 != number2)
		{
			if (number1 > number2)
				number1 = number1 - number2;
			else 
				number2 = number2 - number1;
		}
		printf("%d", number1);
	}
	printf("\n");
}