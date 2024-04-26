#include "shell.h"

/**
* _getenv - Retrieves the value of an environment variable.
* @name: The name of the environment variable.
*
* Return: Pointer to the value part of the matched environment variable string,
*         or NULL if the variable is not found.
*
* Description: Searches the environ global variable for a string that
* matches the environment variable name passed to it and returns
* the string following the equal sign.
*/
char *_getenv(const char *name)
{
	if (name == NULL || *name == '\0' || environ == NULL)
		return (NULL); /* Invalid input or empty environment */

	size_t name_len = strlen(name);

	for (size_t i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			/* Return the value part after '=' */
			return (&environ[i][name_len + 1]);
		}
	}

	return (NULL); /* No matching variable found */
}
