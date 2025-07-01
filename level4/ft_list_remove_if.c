/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>

- Recorrer la lista desde el inicio.
- Comparar cada nodo usando la función cmp(node->data, data_ref).
- Si cmp devuelve 0, significa que el dato es igual a data_ref → entonces elimina el nodo.
- Libera la memoria del nodo usando free.
- Ajusta los punteros para que la lista siga correctamente conectada.
- Continúa hasta el final de la lista.

prev → es el nodo anterior al actual.
current → el nodo actual que estamos examinando.
temp → auxiliar para guardar el nodo a eliminar y luego liberarlo con free.
*/

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp;
    t_list *prev;
    t_list *current;

    // 🧼 Limpiamos las cajitas del principio si hay que quitarlas
    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        temp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(temp);
    }

    // 🧱 Si ya no hay más cajitas, terminamos
    if (!*begin_list)
        return;

    prev = *begin_list;
    current = prev->next;

    // 🧹 Ahora vamos a limpiar las cajitas del medio
    while (current)
    {
        if (cmp(current->data, data_ref) == 0)
        {
            temp = current;
            prev->next = current->next; // Saltamos la cajita actual
            free(temp);                 // La tiramos a la basura
            current = prev->next;       // Seguimos con la próxima
        }
        else
        {
            // Nada que borrar, solo seguimos caminando
            prev = current;
            current = current->next;
        }
    }
}