/* builtins.c */
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

/**
* print_env - Prints all environment variables
*/
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
* exit_shell - Exits the shell cleanly
* @args: Parsed command arguments to handle before exiting
*/
void exit_shell(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]); /* Free each argument */
		i++;
	}
	free(args); /* Free the argument array */
	exit(EXIT_SUCCESS);
}
