/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}

*/

#include "sort_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swapped;
	int temp;
	t_list *current;

	if (!lst)
		return (NULL);
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = lst;
		while (current -> next)
		{
			if (!cmp(current->data), current->next->data)
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swapped = 1; 
			}
			current = current->next;
		}
	}
	return (lst);
}

/*
Recorre la lista muchas veces.
Intercambia datos si están mal ordenados.
Si no se intercambió nada en una pasada, la lista está ordenada.
*/