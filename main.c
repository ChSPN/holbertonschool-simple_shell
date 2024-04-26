#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
* main - Implements a simple shell using getline
* Description: Use getline for input handling in a simple shell.
*              Continuously reads commands from stdin and executes them.
* Return: Returns EXIT_SUCCESS upon termination of the shell.
*/
int main(void)
{
	char *command = NULL; /* buffer for the command input */

	size_t len = 0; /* length of the input buffer */
	ssize_t nread; /* number of characters read */
	char **args; /* argument vector for commands */

	while (1)
	{
		printf(PROMPT);
		fflush(stdout);

		nread = getline(&command, &len, stdin); /* read a line from stdin */
		if (nread == -1)
		{
			printf("\n");
			free(args);
			free(command);
			break; /* exit on read error or EOF */
		}

		if (nread == 1) /* skip empty commands */
		{
			continue;
		}

		args = get_argv(command); /* parse command into arguments */
		shell_execute(args); /* execute the command */
	}

	free(command); /* free the allocated buffer */
	free(args);
	return (EXIT_SUCCESS);
}
