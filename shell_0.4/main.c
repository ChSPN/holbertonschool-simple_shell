#include "shell.h"

/**
* main - Entry point of the simple shell
* Description: This function runs a loop that continually reads commands from the user,
*              parses them, checks for the 'exit' built-in command, executes other commands,
*              and manages memory appropriately to prevent leaks and errors.
* Return: Returns EXIT_SUCCESS upon successful termination of the shell.
*/
int main(void)
{
	char command[MAX_COMMAND_LENGTH]; /* Buffer to hold the command entered by the user */

	char **args;                      /* Array to hold the parsed command and its arguments */

	while (1)
	{
		/* Display the shell prompt */
		printf(PROMPT);
		fflush(stdout);

		/* Read a line of input from the user */
		if (read_line(command, MAX_COMMAND_LENGTH) == -1)
		{
			printf("\n"); // Print a newline on EOF (Ctrl+D)
			break;        // Exit the loop on EOF
		}

		if (strlen(command) == 0)
		{
			continue; // Ignore empty commands and loop again
		}

		/* Parse the command line into arguments */
		args = parse_command(command);

		/* Handle the 'exit' built-in command */
		if (strcmp(args[0], "exit") == 0)
		{
			free(args); // Free allocated memory for arguments before exiting
			break;      // Break the loop and exit the shell
		}

		/* Execute the command if it's not 'exit' */
		execute_command(args);

		/* Free memory allocated for the arguments after command execution */
		free(args);
	}

	return (EXIT_SUCCESS); // Return success code from main
}
