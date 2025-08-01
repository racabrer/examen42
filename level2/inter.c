/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/


#include <unistd.h>

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j;
	int lookup[256] = {};

	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && !lookup[(int)argv[2][j]])
				{
					lookup[(int)argv[2][j]] = 1;
					ft_putchar(argv[2][j]);
				}
				j++;
			}
			i++;
		}
	}
	ft_putchar('\n');
}

