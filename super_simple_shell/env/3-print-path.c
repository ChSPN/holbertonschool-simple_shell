#include <stdio.h>
#include <stdlib.h>

void printpath(void)
{
	char *path = getenv("PATH");

	while (*path != '\0')
	{
		if (*path == ':')
		{
			putchar('\n');
		}
		else
		{
			putchar(*path);
		}

		path++;
	}

	putchar('\n');
}

/**
* main - Entry point that prints all environment variables
*
* Return: Always 0 (Success)
*/
int main(void)
{
	printpath();
	return (0);
}
