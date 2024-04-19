#include "main.h"

/**
* _unsetenv- Retrieves if it functions or not
* Description: it deletes a env variable
*
* Return: -1 if it doesn't work.
*/
int _unsetenv(const char *name)
{
	char **env = environ;
	size_t lenght = strlen(name);

	while (*env != NULL)
	{
		if (strncmp(*env, name, lenght) == 0 && (*env)[lenght] == '=')
		{
			char **current = env;

			while (*(current + 1) != NULL)
			{
				*current = *(current + 1);
				current++;
			}

			*current = NULL;
			return (0);
		}

		env++;
	}

	return (-1);
}
