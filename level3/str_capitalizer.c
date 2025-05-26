/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/


#include <unistd.h>

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' );
}

void ft_putchar (char c)
{
	write (1, &c, 1);
}

void capitalizer(char *s)
{
	int i;
	int new_word = 1;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (new_word)
				s[i] -= 32;
			new_word = 0;
		}
		else if (ft_isspace(s[i-]))
			new_word = 1;
		else 
			new_word = 0;
		ft_putchar(s[i]);
		i++; 
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		ft_putchar('\n');
	else
	{
		while (i < argc)
		{
			capitalizer(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}





