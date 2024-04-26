#include "shell.h"

/**
* main - Simple shell function
* Description: Acts as the entry point for a simple shell.
* It continuously reads commands from the user, parses them, and executes
* using the shell_execute function.
*
* Return: Returns 0 under normal circumstances, though typically doesn't exit.
*/
int main(void)
{
	char *cmd;
	char **args;
	size_t max_cmd_length = MAX_COMMAND_LENGTH;
	ssize_t read;

	while (1)
	{
		cmd = malloc(max_cmd_length * sizeof(char));
		if (cmd == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			continue;
		}

		if (isatty(STDIN_FILENO))
		{
			printf(PROMPT);
		}

		read = getline(&cmd, &max_cmd_length, stdin);
		if (read < 0)
		{
			free(cmd);
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			break;
		}

		args = get_argv(cmd);
		if (args && args[0] != NULL)
		{
			shell_execute(args);
		}

		free(cmd);
	}

	return (0);
}
