#include "shell.h"

/**
 * get_execute_func - Get the execute function
 * Description: Get the execute function
 * @identifier: identifier of action
 * Return: pointer of execute function
*/
int (*get_execute_func(char *identifier))(char **)
{
	int index;

	execute_t executes[] = {
		{"exit", exit_execute},
		{NULL, NULL}
	};

	for (index = 0; index < 1; index++)
	{
		if (executes[index].identifier[0] == identifier[0])
		{
			return (executes[index].ptr_execute);
		}
	}

	return (NULL);
}
