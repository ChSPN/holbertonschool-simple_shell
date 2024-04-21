#include "shell.h"

/**
 * get_argv - Get the arguments values
 * Description: Get the arguments values
 * @cmd: string of command
 * Return: Return the list of arguments
*/
char **get_argv(char cmd[])
{
	char **argv = malloc(MAX_ARGS * sizeof(char *));
	char *token;

	cmd[strlen(cmd) - 1] = '\0';
	token = strtok(cmd, " ");
	for (int index = 0; index < MAX_ARGS; index++)
	{
		argv[index] = token;
		token = strtok(NULL, " ");
	}

	return (argv);
}
