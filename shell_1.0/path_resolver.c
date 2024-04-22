#include "shell.h"

/**
* find_command_in_path - Searches for a command in the PATH environment variable
* @command: The command to find in the PATH
* Return: Full path to the command if found, otherwise NULL
* Description: Iterates through directories listed in PATH to find the executable
*/
char *find_command_in_path(char *command)
{
	char *path = getenv("PATH");

	char *path_copy;

	char *dir;

	char *full_path;

	struct stat st;

	if (path == NULL || command == NULL)
	{
		return (NULL); /* Early return if PATH or command is not provided */
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		return (NULL); /* Failed to allocate memory for path_copy */
	}

	full_path = malloc(MAX_COMMAND_LENGTH);
	if (full_path == NULL)
	{
		free(path_copy); /* Clean up allocated memory if subsequent allocation fails */
		return (NULL);
	}

	for (dir = strtok(path_copy, ":"); dir; dir = strtok(NULL, ":"))
	{
		snprintf(full_path, MAX_COMMAND_LENGTH, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path); /* Command found, return the path */
		}
	}

	free(path_copy);
	free(full_path);
	return (NULL); /* Command not found, return NULL */
}
