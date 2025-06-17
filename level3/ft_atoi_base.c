/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/
#include <unistd.h>

int isspace(int c)
{
    return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

int isvalid(int ch, int baselen)
{
    return ((ch >= '0' && ch <= '9') || 
            (baselen > 10 && ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))));
}

int ft_atoi_base(const char *str, int str_base)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    
    if (str_base < 2 || str_base > 16)
        return (0);
    while (isspace(str[i]))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] && isvalid(str[i], str_base))
    {
        res *= str_base;
        if (str[i] >= '0' && str[i] <= '9')
            res += str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            res += str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            res += str[i] - 'A' + 10;
        i++;
    }
    return (res * sign);
}


#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int base = ft_atoi_base(argv[2], 10);
        if (base < 2 || base > 16) // ✅ Validar base antes de la conversión
        {
            printf("Error: Base inválida\n");
            return (1);
        }
        printf("%d\n", ft_atoi_base(argv[1], base));
    }
    return (0);
}
