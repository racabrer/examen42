/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/
#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_space(char c)
{
	return (c == ' ' || c == '\t' );
}
int main(int argc, char **argv)
{
	int i = 0;
	int space = 0;

	while (is_space(argv[1][i]))
		i++;
	while (argv[1][i])
	{
		if(is_space(argv[1][i]))
			space = 1;
		if(!is_space(argv[1][i]))
		{
			if(space)
				ft_putchar(' ');
			space = 0;
			ft_putchar(argv[1][i]);
		}
		i++;
	}
	ft_putchar('\n');
}