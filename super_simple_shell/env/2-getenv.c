#include "main.h"

/**
 * _getenv - Custom implementation of getenv
 * @name: Name of the environment variable to retrieve
 *
 * Description: Retrieves an environment variable from the system's
 * environment list, matching the provided name.
 * Return: Pointer to the value of the environment variable,
 * or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i, len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}
	}
	return (NULL);
}

/**
 * main - Entry point, checks environment variables passed
 * as command-line arguments
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Description: The program takes one command-line argument representing
 * the name of an environment variable, fetches its value using _getenv,
 * and prints the result. If the variable is not found or if the argument
 * count is incorrect, it informs the user.
 * Return: 0 if successful, 1 if an error occurs
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <env_var_name>\n", argv[0]);
		return (1);
	}

	char *env_var = argv[1];
	char *value = _getenv(env_var);

	if (value != NULL)
	{
		printf("%s: %s\n", env_var, value);
	}
	else
	{
		printf("%s environment variable not found.\n", env_var);
	}
	return (0);
}
