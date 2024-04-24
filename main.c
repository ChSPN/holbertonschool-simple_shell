#include "shell.h"

/**
 * main - Entry point for a simple shell
 * Description: Acts as the entry point for a simple shell. It continuously
 * reads commands from the user, parses them, and executes using the
 * shell_execute function. This function also handles memory management
 * and ensures clean exits on errors or end of input.
 * Return: Returns 0 under normal circumstances, though typically doesn't exit.
 */
int main(void)
{
	char *cmd; /* Buffer for command input */
	char **args; /* Array of pointers for command arguments */
	size_t max_cmd_length = MAX_COMMAND_LENGTH; /* Maximum input length */
	ssize_t read; /* Number of characters read by getline */

	while (1)
	{
		cmd = malloc(max_cmd_length * sizeof(char)); /* Allocate memory: input cmd */
		if (cmd == NULL) /* Check for malloc failure */
		{
			fprintf(stderr, "Memory allocation failed\n");
			continue; /* Skip to the next iteration */
		}
		if (isatty(STDIN_FILENO)) /* Check if stdin is a terminal */
		{
			printf(PROMPT); /* Print prompt */
		}
		read = getline(&cmd, &max_cmd_length, stdin); /* Read a line of input */
		if (read < 0) /* Check for read error or EOF */
		{
			free(cmd); /* Free command buffer */
			if (isatty(STDIN_FILENO))
			{
				printf("\n"); /* Print newline on exit */
			}
			break; /* Exit the loop */
		}
		args = get_argv(cmd); /* Parse command into arguments */
		if (args && args[0] != NULL)
		{
			shell_execute(args); /* Execute the command */
		}
		/* free_argv(args); Free the arguments */
		args = NULL;
		free(cmd); /* Free the command buffer */
		cmd = NULL;
	}

	return (0); /* Return success */
}


/**
 * free_argv - Frees an array of strings
 * @argv: The array of strings to be freed
 *
 * Description: Iterates through each string in the array, frees it, and
 * then frees the array itself. Sets all pointers to NULL to prevent use
 * after free and potential security vulnerabilities.
 */
void free_argv(char **argv)
{
	int i = 0;  /* Index for iterating through the array */

	if (argv != NULL)  /* Ensure the array pointer is not NULL */
	{
		while (argv[i] != NULL)  /* Loop through each string */
		{
			free(argv[i]);  /* Free each string */
			argv[i] = NULL;  /* Set pointer to NULL after freeing */
			i++;  /* Move to the next index */
		}
		free(argv);  /* Free the array of pointers */
		argv = NULL;  /* Set the array pointer to NULL */
	}
}
