#include "shell.h"

#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
* get_argv - Get the arguments values
* Description: Parse a command string into an array of arguments.
* @cmd: string of command
* Return: Returns the list of arguments.
*/
char **get_argv(char cmd[])
{
	char **argv = malloc(MAX_ARGS * sizeof(char *));
	/* Allocate memory for array of pointers to arguments */

	char *token; /* Pointer to hold each parsed token */

	int index; /* Index for the loop to store each argument in argv */

	cmd[strlen(cmd) - 1] = '\0';
	/* Remove the newline character at the end of the cmd string */
	token = strtok(cmd, " ");
	/* Get the first token from the cmd string, tokens are separated by spaces */

	for (index = 0; index < MAX_ARGS; index++)
	/* Iterate through all possible arguments up to MAX_ARGS */
	{
		argv[index] = token; /* Store the current token in the argv array */
		token = strtok(NULL, " ");
		/* Continue to tokenize the string, get next token */
		if (token == NULL) /* If there are no more tokens, break the loop */
		{
			break;
		}
	}

	return (argv); /* Return the array of arguments */
}
