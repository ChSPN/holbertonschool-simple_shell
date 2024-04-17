#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* Include for strcmp */
#include "supershell.h"

/**
* main - Entry point, prints a prompt and echoes user input
* Return: 0 on success, or 1 on failure
*/
int main(void)
{
	int file = fileno(stdin); /* Get file descriptor for stdin */

	char *line;

	/* Read input until EOF */
	while ((line = _getline(file)) != NULL)
	{
		if (strcmp(line, "exit\n") == 0) /* Check if input is "exit" */
		{
			free(line); /* Free memory allocated by getline */
			break; /* Exit loop */
		}

		printf("%s", line);
		printf("$ ");
		free(line); /* Free memory allocated by getline */
	}

	return (0);
}
