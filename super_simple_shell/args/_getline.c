#include <stdio.h>    /* Standard input/output definitions */
#include <stdlib.h>   /* malloc, realloc, free */
#include <unistd.h>   /* read */

#define BUFSIZE 1024  /* Initial buffer size for getline function */

/**
 * _getline - Reads a line from a file descriptor until newline or EOF
 * @file: file descriptor to read from
 * Returns a pointer to the dynamically allocated line on success.
 * Return: NULL on failure or EOF with no data read.
 */

char *_getline(int file)
{
	unsigned int index = 0;

	unsigned int buffer_size = BUFSIZE;

	char *buffer = malloc(buffer_size);
	int bytes_read;
	char *new_buffer;

	if (!buffer)
	{
		perror("malloc failed");
		return (NULL);
	}


	while ((bytes_read = read(file, buffer + index, buffer_size - index - 1)) > 0)
	{
		index += bytes_read;
		if (index > buffer_size - 1)
		{
			buffer_size *= 2;
			new_buffer = realloc(buffer, buffer_size);

			if (!new_buffer)
			{
				free(buffer);
				perror("realloc failed");
				return (NULL);
			}
			buffer = new_buffer;
		}
	}

	if (bytes_read == 0 && index == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[index] = '\0';
	return (buffer);
}
