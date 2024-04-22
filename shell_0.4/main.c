#include "shell.h"

/**
* main - Entry point for the simple shell
* Description: Runs a loop that continuously reads commands,
* checks for the 'exit' built-in command, and executes other commands.
* Return: Returns EXIT_SUCCESS upon exiting the shell
*/
int main(void)
{
	char command[MAX_COMMAND_LENGTH]; /* Buffer for the command input */

	char **args; /* Array of string pointers for the command and its arguments */

	while (1)
	{
		/* Display prompt */
		printf(PROMPT);
		fflush(stdout);

		/* Read command from standard input */
		if (read_line(command, MAX_COMMAND_LENGTH) == -1)
		{
			printf("\n");
			break; /* Handle EOF */
		}

		/* Check for an empty command */
		if (strlen(command) == 0)
		{
			continue; /* Ignore empty commands and prompt again */
		}

		/* Parse the command */
		args = parse_command(command);

		/* Check for 'exit' command */
		if (strcmp(args[0], "exit") == 0)
		{
			free(args); /* Free allocated memory before exiting */
			break; /* Exit the shell */
		}

		/* Execute the command if not 'exit' */
		execute_command(args);

		/* Freeing any allocated memory */
		if (args)
		{
			free(args); /* Free the args after executing the command */
		}
	}
	return (EXIT_SUCCESS); /* Return success code from main */
}
