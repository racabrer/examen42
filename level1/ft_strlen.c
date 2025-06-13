/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:48:20 by racabrer          #+#    #+#             */
/*   Updated: 2025/06/12 18:57:38 by racabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);
*/

#include <stdio.h> 

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;
	return(i);
}

int main(void)
{
	char *txt = "Hola mundo";
	int len;
	
	len = ft_strlen(txt);

	printf("La longitud de la cadena es %s es: %d\n", txt, len);

	return (0);
	
}