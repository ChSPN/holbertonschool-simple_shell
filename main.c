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
	char *argv[2] = { NULL, NULL };

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
		cmd[strlen(cmd) - 1] = '\0';
		argv[0] = strtok(cmd, " ");
		if (argv[0] != NULL)
			shell_execute(argv);
		free(cmd);
	}
	return (0);
}