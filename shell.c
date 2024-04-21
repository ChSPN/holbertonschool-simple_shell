#include "shell.h"

/**
 * main - simple shell function
 * Description: simple shell function
 * Return: state of simple shell execution
*/
int main(void)
{
	char *cmd;
	size_t max_cmd_length = 256;
	char *argv[2] = { NULL, NULL };

	while (1)
	{
		cmd = malloc(max_cmd_length * sizeof(char));
		printf("#cisfun$ ");
		if (getline(&max_cmd_length, &max_cmd_length, stdin) < 0)
		{
			free(cmd);
			printf("\n");
			exit(0);
		}
		cmd[strlen(cmd) - 1] = '\0';
		argv[0] = strtok(cmd, " ");
		if (argv != NULL && argv[0] != NULL)
			shell_execute(argv);
		free(cmd);
	}
	return (0);
}
