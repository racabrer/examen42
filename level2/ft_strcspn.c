/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

STRCSPN(3) (simplified)

NAME
    strcspn -- span a string
LIBRARY
    Standard C Library (libc, -lc)
SYNOPSIS
    #include <string.h>
    size_t strcspn(const char *s, const char *charset);
DESCRIPTION
    The strcspn() function spans the initial part of the null-terminated
string s as long as the characters from s do not occur in the null-
terminated string charset (it spans the complement of the charset). In
other words, it computes the string array index of the first character
of s which is also in charset, else the index of the first null character.
RETURN VALUES
    The strcspn() functions return the number of characters spanned.

*/
#include <stdio.h>


size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t j;

	i = 0;

	while(s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
