#include "shell.h"

/**
 * main - simple shell function
 * Description: simple shell function
 * Return: state of simple shell execution
*/
int main(void)
{
	char *cmd;
	char **argv;
	size_t max_cmd_length = 256;

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
		argv = get_argv(cmd);
		if (argv != NULL && argv[0] != NULL)
			shell_execute(argv);
		free(argv);
		free(cmd);
	}
	return (0);
}
