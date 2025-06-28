Otra versión de rstr_capitalize


#include <unistd.h>

// Devuelve 1 si el carácter es una letra (a-z o A-Z), 0 si no lo es
int is_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

// Convierte una letra a minúscula, si es mayúscula
char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

// Convierte una letra a mayúscula, si es minúscula
char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

// Función principal que convierte el string al formato deseado
void rstr_cap(char *str)
{
    int i;                // Índice para recorrer la cadena
    int word_start;       // Marca si estamos al comienzo de una palabra
    int last_letter_pos;  // Guarda la posición del último carácter que sea letra en una palabra
    char c;               // Carácter actual
    char upper;           // Versión en mayúscula de la última letra

    i = 0;
    word_start = 1;
    last_letter_pos = -1;

    // Recorremos cada carácter del string
    while (str[i])
    {
        c = str[i];

        if (is_letter(c)) // Si es una letra...
        {
            c = to_lower(c);       // Lo convertimos a minúscula
            last_letter_pos = i;   // Guardamos esta posición como posible última letra de la palabra
            word_start = 0;        // Ya no estamos al comienzo de una palabra
        }
        else if (c == ' ' || c == '\t') // Si encontramos un espacio o tabulación...
        {
            // Si teníamos una palabra con letras, capitalizamos la última letra que vimos
            if (last_letter_pos != -1)
            {
                upper = to_upper(str[last_letter_pos]); // Convertimos la letra a mayúscula
                write(1, "\b", 1);                      // Retrocedemos un carácter en la salida
                write(1, &upper, 1);                    // Imprimimos la versión mayúscula
            }
            word_start = 1;        // Ahora estamos al comienzo de una nueva palabra
            last_letter_pos = -1;
