/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>

int *ft_range(int start, int end)
{
    int i = 0;
    int len;

    // Determinar el tamaño del array
    if (end >= start)
        len = end - start + 1;
    else
        len = start - end + 1;

    // Reservar memoria
    int *range = (int *)malloc(len * sizeof(int));
    if (!range)
        return (NULL);

    // Llenar el array con valores consecutivos
    while (i < len)
    {
        if (start < end)
            range[i] = start++;
        else
            range[i] = start--;
        i++;
    }

    return (range);
}


int main()
{
    int *arr;
    int i;
    int start, end;
    int size;

    // Prueba 1: Rango positivo
    start = 1;
    end = 5;
    size = abs(end - start) + 1;
    arr = ft_range(start, end);
    if (!arr)
        return (1);
    printf("Rango (%d, %d): ", start, end);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);

    // Prueba 2: Rango con valores negativos
    start = -3;
    end = 2;
    size = abs(end - start) + 1;
    arr = ft_range(start, end);
    if (!arr)
        return (1);
    printf("Rango (%d, %d): ", start, end);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);

    // Prueba 3: Un solo número
    start = 0;
    end = 0;
    size = abs(end - start) + 1;
    arr = ft_range(start, end);
    if (!arr)
        return (1);
    printf("Rango (%d, %d): ", start, end);
    printf("%d\n", arr[0]);
    free(arr);

    // Prueba 4: Rango decreciente
    start = 5;
    end = 1;
    size = abs(end - start) + 1;
    arr = ft_range(start, end);
    if (!arr)
        return (1);
    printf("Rango (%d, %d): ", start, end);
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);

    return 0;
}

