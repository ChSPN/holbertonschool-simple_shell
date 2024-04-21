#include "shell.h"

/**
 * main - simple shell function
 * Description: simple shell function
 * Return: state of simple shell execution
*/
int main(void)
{
	char cmd[MAX_CMD_LEN];
	char *argv[2] = { NULL, NULL };

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			exit(0);
		}
		cmd[strlen(cmd) - 1] = '\0';
		argv[0] = strtok(cmd, " ");
		shell_execute(argv);
	}
	return (0);
}
