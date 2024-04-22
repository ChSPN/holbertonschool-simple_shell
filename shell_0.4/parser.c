#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
* parse_command - Parses the command line into arguments
* @command: the command entered by the user
* Return: pointer to the dyn allocated array of pointers to the arguments
*/
char **parse_command(char *command)
{
	char **args;

	char *token;

	int i = 0;

	args = (char **) malloc((MAX_ARGS + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("Failed to allocate args");
		return (NULL);
	}

	token = strtok(command, " ");
	while (token != NULL && i < MAX_ARGS)
	{
		args[i] = strdup(token); /* Duplicate the token */
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL; /* Ensure the last argument is NULL for execvp */

	return (args);
}
