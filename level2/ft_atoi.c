/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

int ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else 
		return (0);
}
int ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
int ft_atoi(const char *str)
{
	int res = 0;
	int i = 0;
	int s = 1;

	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res *= s);
}

