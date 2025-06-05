/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int		max(int* tab, unsigned int len)
{
	int count = 0;
	int result = 0;
	int i = 0;

	if (len > 0)
	{
		while (count < len)
		{
			if (tab[i] > result)
				result = tab[i];
			i++;
			count++;
		}
		return (result);
	}
	return (0);
}

#include <stdio.h>

int main()
{
	int int_tab[] = {1, 3, 2, 10, 9};
	printf("%d", max(int_tab, 5));
}

/*
EXPLICACIÓN
Esta función toma dos parámetros:

int* tab → Un puntero a un array de enteros.

unsigned int len → La longitud del array.

Su objetivo es encontrar el valor máximo dentro del array. Ahora desglosémoslo:

Inicialización de variables
count = 0 → Lleva la cuenta de iteraciones.

result = 0 → Inicializa el valor máximo en 0. Esto puede ser un problema si todos los números del array son negativos.

i = 0 → Se usa para recorrer el índice del array.

Condición inicial
Antes de entrar en el bucle, se comprueba if (len > 0). Si el array tiene longitud 0, la función retorna 0 inmediatamente.

Bucle while
La función recorre el array usando count como condición de parada:

Compara tab[i] con result.

Si tab[i] es mayor que result, lo actualiza.

Incrementa i y count para recorrer el array.

Retorno del valor máximo
Después de recorrer todo el array, la función devuelve el valor máximo encontrado en result. En caso de que len == 0, devuelve 0.

Posibles mejoras
Inicializar result correctamente → En lugar de 0, podría inicializarse como tab[0], evitando errores con números negativos.

Uso de for en vez de while → Podría simplificarse el código eliminando count e iterando directamente con i.

Evitar acceder a tab[i] si len == 0 → Para evitar accesos indebidos a memoria.

*/