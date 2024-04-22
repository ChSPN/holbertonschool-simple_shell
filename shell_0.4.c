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
	size_t max_cmd_length = 256;
	execute_t executes[] = {
		{"exit", exit_execute},
		{ NULL, NULL }
	};

	while (isExit == 0)
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
