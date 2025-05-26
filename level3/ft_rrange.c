/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0. 
*/
#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int *r;
	int len;

	if (end >= start)
		len = end - start + 1;
	else 
		len = start - end - 1;
	r = (int *)malloc(sizeof(int) * len);
	if (!r)
		return (NULL);
	while (len > 0)
	{
		if (end >= start)
			r[len -1] = start ++;
		else
			r[len - 1] = start--;
		len--;
	}
	return(r);
}

/*
Explicación de lo que hace la función: 
	1. Calcular el tamaño del array (len)
		- Si end >= start, el tamaño es end - start + 1
		- Si start > end, el tamaño es start - end + 1
	2. Reserva memoria dinámica (malloc())
		- Se usa malloc() para asignar espacio suficiente(sizeof(int) * len)
		- Si la asignación falla, la función retorna NULL.
	3. Llena el array e orden inverso (while (len > 0))
		- Comienza desde el final (r[len -1])
		- Si end >= start, coloca start y lo incrementa (start ++).
		- Si start > end, coloca start y lo decrementa (start--).
	4. Retorna el puntero al array (return r)
		- La función devuelve el puntero r, que apunta al primer elemento del array.
*/

int main()
{
    int *arr;
    int i;
    int start = 1, end = 5;
    int size = (end >= start) ? end - start + 1 : start - end + 1;

    arr = ft_rrange(start, end);
    if (!arr)
        return (1);

    printf("Rango inverso (%d, %d): ", start, end);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}