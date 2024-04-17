#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
* is_executable - Checks if the file at given path is executable by the owner.
* @filepath: The file path to check for executable permission.
*
* Return: 1 if the file is executable by the owner, 0 otherwise.
*/
int is_executable(char *filepath)
{
	struct stat st;

	if (stat(filepath, &st) == 0 && (st.st_mode & S_IXUSR))
	{
		return (1);
	}
	return (0);
}

/**
* main - Searches for executables in the PATH environment variable.
* @argc: Argument count.
* @argv: Argument vector, expected to contain filenames to search for in PATH.
*
* Return: 0 on finding the first executable file, 1 if no executable is found
*         or an error occurs.
*/
int main(int argc, char **argv)
{
	char *path;

	char *token;

	int i;

	char filepath[1024];

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	path = getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "PATH environment variable is not set.\n");
		return (1);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		for (i = 1; i < argc; i++)
		{
			snprintf(filepath, sizeof(filepath), "%s/%s", token, argv[i]);
			if (is_executable(filepath))
			{
				printf("%s\n", filepath);
				return (0);
			}
		}
		token = strtok(NULL, ":");
	}
	printf("Command not found in PATH.\n");
	return (1);
}
