#include <stdio.h>
#include <stdlib.h>

/**
* printpath -Prints the path from the root node to a given node
* @path: Pointer to the node to which the path is printed
*
* Description: recursively prints the path from root to given node
* Return: 0
*/

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
