#include "shell.h"

char **parse_command(char *command)
{
	static char *args[MAX_ARGS + 1];

	int i = 0;

	args[i] = strtok(command, " ");
	while (args[i] != NULL && i < MAX_ARGS)
	{
		args[++i] = strtok(NULL, " ");
	}
	args[MAX_ARGS] = NULL; /* Ensure the last argument is NULL for execvp */
	return (args);
}
