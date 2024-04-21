#include "shell.h"

/**
 * main - simple shell function
 * Description: simple shell function
 * Return: state of simple shell execution
*/
int main(void)
{
	char *cmd;
	char *argv[2] = { NULL, NULL };

	while (1)
	{
		cmd = malloc(MAX_CMD_LEN * sizeof(char));
		printf("#cisfun$ ");
		if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
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
