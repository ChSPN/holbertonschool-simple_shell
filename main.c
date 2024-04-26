#include "shell.h"

/**
* main - Entry point of the simple shell program.
 *
 * Description:
 * The main function serves as the initial entry point for the simple shell.
 * It enters an infinite loop that continuously reads user input,
 * processes commands, and manages the execution of those commands
 * via child processes.
 * Return: 0 if success
*/

int main(void)
{
	char *command;

	while (1)
	{
		command = initialize_command();
		if (command != NULL)
		{
			handle_command(command);
			free(command); /* Ensure memory is freed after handling the command */
		}
	}
	return (0);
}
