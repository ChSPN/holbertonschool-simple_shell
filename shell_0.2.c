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

	while (1)
	{
		cmd = malloc(MAX_CMD_LEN * sizeof(char));
		printf("#cisfun$ ");
		if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
		{
			printf("\n");
			exit(0);
		}
		argv = get_argv(cmd);
		shell_execute(argv);
		free(argv);
		free(cmd);
	}
	return (0);
}
