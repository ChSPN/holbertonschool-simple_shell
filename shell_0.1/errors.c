#include "shell.h"

/**
* print_error - Prints an error message when command execution fails.
*/
void print_error(void)
{
	char *error = "Command not found\n";

	write(STDERR_FILENO, error, strlen(error));
}
