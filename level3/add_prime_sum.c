/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putnbr(int nbr)
{
	unsigned int nb;

	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -nbr;
	}
	else 
		nb = nbr;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
int is_prime(int nbr)
{
	int i;
	if (nbr < 2)
		return (0);
	i = 2;
	while (i<= nbr / 2)
	{
		if (nbr % i == 0)
			return(0);
		i++;
	}
	return(1);	
}

int ft_atoi (char *str)
{
	int res;
	int sign;
	int i;

	res = 0;
	sign = 1;;
	i = 0;
	while( str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	res *= sign;
	return (res);
}


int main (int argc, char **argv)
{
	int n;
	int sum;

	if (argc != 2 || ft_atoi(argv[1]) <= 0)
	{
		write(1, "0\n", 2);
		return(0);
	}
	n = ft_atoi(argv[1]);
	sum = 0;
	while (n > 1)
	{
		if (is_prime(n))
			sum += n;
		n--;
	}
	ft_putnbr(sum);
	ft_putchar('\n');
}