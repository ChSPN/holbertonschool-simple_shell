#include "shell.h"

/**
 * get_execute_func - Get the execute function
 * Description: Get the execute function
 * @executes: list of actions
 * @identifier: identifier of action
 * Return: pointer of execute function
*/
int (*get_execute_func(execute_t executes[], char *identifier))(char **)
{
	int index = 0;

	while (executes[index].identifier)
	{
		if (strcmp(executes[index].identifier, identifier) == 0)
		{
			return (executes[index].ptr_execute);
		}

		index++;
	}

	return (NULL);
}
