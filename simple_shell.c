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
	int status;
	int isExit = 0;
	int (*execute)(char **) = NULL;
	execute_t executes[] = {
		{"exit", exit_execute},
		{"env", printenv_execute},
		{ NULL, NULL }
	};

	while (isExit == 0)
	{
		cmd = malloc(MAX_CMD_LEN * sizeof(char));
		printf("#cisfun$ ");
		if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL)
		{
			free(cmd);
			printf("\n");
			exit(0);
		}
		argv = get_argv(cmd);
		if (argv != NULL && argv[0] != NULL)
		{
			execute = get_execute_func(executes, argv[0]);
			if (execute != NULL)
			{
				status = execute(argv);
				if (status != 0)
					isExit = 1;
			}
			else
				shell_execute(argv);
		}
		free(argv);
		free(cmd);
	}
	return (0);
}
