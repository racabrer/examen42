/*
Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>

Funcionamiento:

1️. Comprobar el número de argumentos (argc). 
2️. Recorrer s2, buscando los caracteres de s1 en el mismo orden. 
3️. Si s1 se encuentra en s2 en orden → imprime 1. 
4️. Si algún carácter de s1 falta o está en desorden → imprime 0.

*/


int main(int argc, char **argv)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}
		if (argv[1][i] == '\0') // si llegamos al final de s1, fue escondido exitosamente
			write(1, "1\n", 2);
		else
			write(1, "0\n", 2);
	}
	else
		write(1, "\n", 1);
	return (0);
}
