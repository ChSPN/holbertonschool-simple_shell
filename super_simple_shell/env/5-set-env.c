#include "main.h"

/**
 * _setenv - Update or add environment variable.
 * @name: Name of the environment variable to retrieve
 * @value: The value of the variable environment
 * @overwrite: Overwrite the variable
 * Description: function that changes or adds an environment variable.
 * Return: State of update
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	/*Check if the variable already exists*/
	char *env_var = getenv(name);

	if (env_var != NULL && !overwrite)
	{
		return (0);
	}

	/*+2 for '=' and '\0'*/
	size_t size = strlen(name) + strlen(value) + 2;
	char *new_var = malloc(size);

	if (new_var == NULL)
	{
		perror("malloc");
		return (-1);
	}

	sprintf(new_var, "%s=%s", name, value);

	/*If variable exists and overwrite is true, remove it first*/
	if (env_var != NULL)
	{
		unsetenv(name);
	}

	/*Add the new variable*/
	if (putenv(new_var) != 0)
	{
		perror("putenv");
		free(new_var);
		return (-1);
	}

	return (0);
}
