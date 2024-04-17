#include <stdio.h>

/* Declaration of the extern variable environ pointing to the environment */
extern char **environ;

/**
* main - Entry point that prints all environment variables
*
* Return: Always 0 (Success)
*/
int main(void)
{
	int i = 0; /* Index for environment variables */

	/* Loop through each environment variable in the environ array until NULL */
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}
