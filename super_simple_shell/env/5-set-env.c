#include "main.h"

/**
 * changeOrAddEnvVar- Update or add environment variable.
 * @name: Name of the environment variable to retrieve
 * @value: The value of the variable environment
 * Description: function that changes or adds an environment variable.
 */
void changeOrAddEnvVar(const char *name, const char *value)
{
	char *var;
	size_t nameLength = strlen(name);

	for (int index = 0; environ[index] != NULL; index++)
	{
		/* Si la variable d'environnement commence par le nom spécifié*/
		if (strncmp(environ[index], name, nameLength)
		== 0 && environ[index][nameLength] == '=')
		{
			var = malloc(nameLength + strlen(value) + 2); /* +2 pour '=' et '\0'*/
			sprintf(var, "%s=%s", name, value);
			environ[index] = var;
			return;
		}
	}

	var = malloc(nameLength + strlen(value) + 2);
	sprintf(var, "%s=%s", name, value);
	putenv(var);
}

/**
 * main - to test application
 * Description: test
 * Return: a interger
*/
int main(void)
{
	char **env = environ;

	changeOrAddEnvVar("TEST", "TEST1");
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	/*Changer ou ajouter une variable d'environnement*/
	printf("\n\n\n");
	changeOrAddEnvVar("TEST", "TEST2");

	env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	return (0);
}
