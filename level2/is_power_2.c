/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

int	    is_power_of_2(unsigned int n)
{
	/*
		we will initialize a test variable to 1, and we will multiply it by 2 
		until is equal to or greater than the variable we have been given as a 
		parameter (n). If the 2 variables are equal it means that is a power of 2 
		(since we have always multiplied this number by 2).
	*/

/*
int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    while (n % 2 == 0)
        n = n / 2;
    return (n == 1);
}

#include <stdio.h>

int is_power_of_2(unsigned int n);

int main(void)
{
    printf("0: %d\n", is_power_of_2(0));
    printf("1: %d\n", is_power_of_2(1));
    printf("2: %d\n", is_power_of_2(2));
    printf("3: %d\n", is_power_of_2(3));
    printf("4: %d\n", is_power_of_2(4));
    printf("5: %d\n", is_power_of_2(5));
    printf("8: %d\n", is_power_of_2(8));
    printf("16: %d\n", is_power_of_2(16));
    printf("31: %d\n", is_power_of_2(31));
    printf("32: %d\n", is_power_of_2(32));
    printf("33: %d\n", is_power_of_2(33));
    printf("64: %d\n", is_power_of_2(64));
    printf("127: %d\n", is_power_of_2(127));
    printf("128: %d\n", is_power_of_2(128));

    return 0;
}

*/
	int test;

	test = 1;
	while (test <= n)
	{
		if (test == n)
			return (1); //test is a power of 2
		test = test * 2;
	} 
	/*
		we will leave the loop if the test variable is greater than n, this means 
		that it is not a power of 2 and we need to retun 0.
	*/
	return (0);
}

#include <stdio.h>

int main()
{
	printf("%d", is_power_of_2(16));
}