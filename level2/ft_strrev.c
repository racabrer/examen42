/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/


#include <stdio.h>

char    *ft_strrev(char *str)
{
	int i;
	int len;
	char tmp;

	i = 0;
	len = 0;
	while(str[len])
		len++;
	while (i < len - 1)
	{
		tmp = str[i];
		str[i] = str[len -1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return(str);
	
}