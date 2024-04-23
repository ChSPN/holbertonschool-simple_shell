#include "shell.h"

/**
* Function to read a line of input from stdin
*/
int read_line(char *buffer, int size)
{
	int count = 0;

	char c;

	while (read(STDIN_FILENO, &c, 1) > 0 && c != '\n' && count < size - 1)
	{
		buffer[count++] = c;
	}
	buffer[count] = '\0';

	/* Use parentheses around the return value as specified */
	return (c == '\n' ? count : -1);
}
