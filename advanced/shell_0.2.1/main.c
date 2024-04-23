#include "shell.h"

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	char **args;

	while (1)
	{
		printf(PROMPT);
		fflush(stdout);

		if (read_line(command, MAX_COMMAND_LENGTH) == -1)
		{
			printf("\n");
			break;
		}

		if (strlen(command) == 0)
		{
			continue;
		}

		args = parse_command(command);
		execute_command(args);
	}
	return (EXIT_SUCCESS);
}
