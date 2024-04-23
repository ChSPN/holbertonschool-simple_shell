#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * my_getline - Reads a line from standard input.
 * @lineptr: Pointer to the buffer containing the read line.
 * @n: Size of the buffer.
 * Return: The number of characters read, including the newline character,
 *         or -1 on failure or EOF.
 */
ssize_t my_getline(char **lineptr, size_t *n)
{
    static char buffer[BUFFER_SIZE];
    static int buffer_size = 0;
    static int buffer_index = 0;
    char c;
    int idx = 0;

    if (!lineptr || !n)
    {
        return (-1);
    }

    if (*lineptr == NULL || *n == 0)
    {
        *n = BUFFER_SIZE;
        *lineptr = malloc(*n);
        if (!*lineptr)
        {
            return (-1);
        }
    }

    while (1)
    {
        if (buffer_index >= buffer_size)
        {
            buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            buffer_index = 0;
            if (buffer_size <= 0)
            {
                return (-1); /* Error or EOF */
            }
        }

        c = buffer[buffer_index++];
        if (idx >= (int)(*n - 1)) /* Check if there's room in buffer */
        {
            *n *= 2;
            *lineptr = realloc(*lineptr, *n);
            if (!*lineptr)
            {
                return (-1);
            }
        }

        (*lineptr)[idx++] = c;
        if (c == '\n')
        {
            break; /* End of line */
        }
    }

    (*lineptr)[idx] = '\0'; /* Null-terminate the string */
    return (idx); /* Return the number of characters read, not including the null */
}
