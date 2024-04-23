#include "shell.h"

/**
* main - simple shell function
* Description: simple shell function
* Return: state of simple shell execution
*/
int main(void)
{
	char *cmd;

	size_t max_cmd_length = MAX_COMMAND_LENGTH;
	char **argv;

	while (1)
	{
		cmd = malloc(max_cmd_length * sizeof(char));
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		if (getline(&cmd, &max_cmd_length, stdin) < 0)
		{
			free(cmd);
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit(0);
		}
		argv = get_argv(cmd); /* parse command into arguments */
		if (argv[0] != NULL)
			shell_execute(argv);
		free(cmd);
	}
	return (0);
}
