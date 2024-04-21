#include "shell.h"

/**
 * printenv_execute - Print the environments variables
 * Description: Print the environments variables
 * @argv: list of command
 * Return: state of execution
*/
int printenv_execute(char *argv[] __attribute__((unused)))
{
	int index = 0;

	while (environ[index])
	{
		printf("%s\n", environ[index]);
		index++;
	}

	return (0);
}
