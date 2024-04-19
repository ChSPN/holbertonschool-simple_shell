#include "main.h"

/**
* main - Entry point that prints all environment variables
*
* Return: Always 0 (Success)
*/
int main(void)
{
	int index = 0; /* Index for environment variables */

	/* Loop through each environment variable in the environ array until NULL */
	while (environ[index])
	{
		printf("%s\n", environ[index]);
		index++;
	}

	return (0);
}
