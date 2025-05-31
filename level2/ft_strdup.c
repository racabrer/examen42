/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

Crea una nueva cadena de memoria dinámica 
Es útil para trabajar con copias independientes de strings 

*/
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char *tmp;
	int len;
	int i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[i] = 0; //terminar correctamente la cadena de carateres en C.
	return (tmp);
}

#include <stdio.h>

int main()
{
	char *a;
	a = "Hello Word";
	printf("%s\n", ft_strdup(a));
}