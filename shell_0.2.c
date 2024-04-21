#include "shell.h"

/**
 * main - simple shell function
 * Description: simple shell function
 * Return: state of simple shell execution
*/
int main(void)
{
	char cmd[MAX_CMD_LEN];
	char *argv[MAX_ARGS];
	char *token;

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			exit(0);
		}
		cmd[strlen(cmd) - 1] = '\0';
		token = strtok(cmd, " ");
		for (int i = 0; i < MAX_ARGS; i++)
		{
			argv[i] = token;
			token = strtok(NULL, " ");
		}
		shell_execute(argv);
	}
	return (0);
}
