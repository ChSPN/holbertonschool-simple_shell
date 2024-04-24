#include "shell.h"

/**
 * get_argv - Get the arguments values
 * Description: Parse a command string into an array of arguments.
 * @cmd: string of command
 * Return: Returns the list of arguments.
 */

char **get_argv(char cmd[])
{
	char **argv = (char **)malloc((MAX_ARGS + 1) * sizeof(char *));
	int argc = 0;
	char *start = cmd;
	char *end, *token, *quote_end;

	if (argv == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for argv\n");
		exit(EXIT_FAILURE);
	}
	while ((token = strtok_r(start, " ", &end)) != NULL && argc < MAX_ARGS)
	{
		if (token[0] == '"') /* Check if the token starts with a quote */
		{
			char *quote_end = strchr(token + 1, '"');

			if (quote_end == NULL)
			{
				fprintf(stderr, "Unmatched quote in command: %s\n", cmd);
				exit(EXIT_FAILURE);
			}
			argv[argc++] = strndup(token + 1, quote_end - token - 1);
			if (argv[argc - 1] == NULL)
			{
				fprintf(stderr, "Failed to allocate memory for argument\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			argv[argc++] = strdup(token);
			if (argv[argc - 1] == NULL)
			{
				fprintf(stderr, "Failed to allocate memory for argument\n");
				exit(EXIT_FAILURE);
			}
		}
		start = NULL; /* For subsequent calls to strtok_r */
	}
	argv[argc] = NULL;
	return (argv);
}
