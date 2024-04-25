#include "shell.h"

/**
* _getenv - Retrieves the value of an environment variable.
* @name: The name of the environment variable.
*
* Return: Pointer to the value part of the matched environment variable string.
*
* Description: Searches the environ global variable for a string that
* matches the environment variable name passed to it and returns
* the string following the equal sign.
*/
char *_getenv(const char *name)
{
	int i = 0;

	int name_len = strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (&environ[i][name_len + 1]); /* Return the value part after '=' */
		}
		i++;
	}
	return (NULL); /* No matching variable found */
}
