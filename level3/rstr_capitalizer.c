/*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>

El objetivo del prograna es convertir cada palabra de la entrada a minúsculas,
excepto la última letra de cada palabra, que debe estar en mayúscula.

Una "palabra" se define como una secuencia de caracteres separados por espacios,
tabulaciones o cualquier carácter de espacio (isspace).
*/

#include <unistd.h>

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void r_capitalizer(char *s)
{
	int i; 

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if ((s[i] >= 'a' && s[i] <= 'z') && ft_isspace(s[i +1])) 
			s[i] -= 32;
		ft_putchar(s[i]);
		i++;
	}
}

int main (int argc, char **argv)
{
	int i = 1;

	if (argc < 2)
		ft_putchar('\n');
	else
	{
		while (i < argc)
		{
			r_capitalizer(argv[i]);
			if ( i < argc - 1)
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
