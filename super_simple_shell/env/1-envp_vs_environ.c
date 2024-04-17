#include <stdio.h>

/* Declaration of the extern variable environ pointing to the environment */
extern char **environ;

/**
* main - Entry point that prints addresses of envp and environ
* @argc: Argument count
* @argv: Argument vector
* @envp: Environment variables array
*
* Return: Always 0 (Success)
*/
int main(int argc, char *argv[], char *envp[])
{
	(void) argc, (void) argv;

	printf("Address of local envp: %p\n", (void *)envp);
	printf("Address of global environ: %p\n", (void *)environ);

	return (0);
}
