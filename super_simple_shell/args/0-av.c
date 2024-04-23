#include <stdio.h>

/**
* main - Entry point of the program that prints all command-line arguments
* @argv: An array of character strings representing the arguments provided
* @argc: unused
* Return: Always returns 0
*/
int main(int argc, char **argv)
{
	/* The unused parameter */
	(void)argc;

	/* Iterates over each argument until NULL is found */
	while (*argv)
	{
		printf("%s\n", *argv);
		argv++;
	}

	return (0);
}
