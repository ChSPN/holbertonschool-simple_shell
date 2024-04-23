#include "main.h"

/**
* getpath - Retrieves PATH environment variable and parses it into linked list
* Description: recursively prints the path from root to given node
* Return: Pointer to head of the linked list containing each directory in PATH
*/
path_t *getpath(void)
{
	int index = 0;
	path_t *paths = NULL;
	path_t *current = NULL;
	path_t *new = NULL;
	char *path = getenv("PATH");

	paths = (path_t *)malloc(sizeof(path_t));
	paths->value = (char *)malloc(sizeof(char) * 128);
	current = paths;
	while (*path != '\0')
	{
		if (*path == ':')
		{
			current->value[index] = '\0';
			index = 0;
			new = (path_t *)malloc(sizeof(path_t));
			current->next = new;
			current = new;
			current->value = (char *)malloc(sizeof(char) * 128);
		}
		else
		{
			current->value[index] = *path;
			index++;
		}

		path++;
	}

	return (paths);
}
