#include <stdio.h>
#include <stdlib.h>

/**
* main - Entry point, prints a prompt and echoes user input
* Return: 0 on success, or 1 on failure
*/

int main(void)
{
	char *line = NULL;

	size_t len = 0;
	ssize_t nread;

	/* Print the prompt */
	printf("$ ");
	/* Read input until EOF */
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		printf("%s", line);
		printf("$ ");
	}
	free(line); /* Free memory allocated by getline */
	return (0);
}
