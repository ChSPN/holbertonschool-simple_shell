#include "shell.h"

/**
 * printf_sdtin - Prints a string to stdout if stdin is a terminal.
 * Description: This function is used to print a string to stdout only if.
 * @str: The string to print.
*/
void printf_sdtin(const char *str)
{
	if (isatty(STDIN_FILENO))
		printf("%s", str);
}

/**
* main - Simple shell function
* Description: Acts as the entry point for a simple shell.
* It continuously reads commands from the user, parses them, and executes
* using the shell_execute function.
* Score au checker: 23/30
* Return: Returns 0 under normal circumstances, though typically doesn't exit.
*/
int main(void)
{
	char *cmd;
	char **args;
	size_t max_cmd_length = MAX_COMMAND_LENGTH;
	int read;
	int (*execute)(char **) = NULL;
	execute_t executes[] = { {"exit", exit_execute}, {NULL, NULL} };

	while (1)
	{
		cmd = malloc(max_cmd_length * sizeof(char));
		if (cmd == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(0);
		}
		printf_sdtin(PROMPT);
		read = getline(&cmd, &max_cmd_length, stdin);
		if (read < 0)
		{
			free(cmd);
			printf_sdtin("\n");
			continue;
		}
		args = get_argv(cmd);
		if (args && args[0] != NULL)
		{
			execute = get_execute_func(executes, args[0]);
			if (execute != NULL && execute(args) != 0)
			{
				free(cmd);
				free(args);
				exit(0);
			}
			else if (execute == NULL)
				shell_execute(args);
		}
		free(cmd);
	}
	return (0);
}
