#include "shell.h"

static builtin_t builtins[] = {
	{"exit", builtin_exit},
	{"cd", builtin_cd},
	{NULL, NULL}  /* End marker */
};

/**
* get_builtins - Accessor for built-in commands array
* Description: Provides access to the array containing all built-in commands.
* This allows the shell to query and execute built-in commands as needed.
* Return: Pointer to the first element of the array of built-in commands
*/

builtin_t *get_builtins(void)
{
	return (builtins);
}

/**
* builtin_exit - Handles the 'exit' built-in command to exit the shell
* @args: Command arguments, unused in this function
* Description: Exits the shell when the 'exit' command is invoked.
* The args are ignored because 'exit' does not require any.
*
* Return: Does not return, terminates the process
*/

int builtin_exit(char **args)
{
	(void)args;  /* Ignore unused parameter */
	exit(0);
	return (0);  /* Not reached */
}

/**
* builtin_cd - Handles the 'cd' built-in command to change directory
* @args: Command arguments, args[1] is expected to be the target directory
* Description: Changes the shell’s CD to the one specified in args[1].
* If args[1] is not provided, it reports an error.
* Return: 1 on successfully changing the directory, 0 otherwise
*/
int builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: expected argument to \"cd\"\n");
		return (1);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (0);
		}
	}
	return (1);
}
