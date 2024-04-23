#include "shell.h"

/**
* display_prompt - Displays the command prompt.
*/
void display_prompt(void)
{
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}

/**
* prompt_loop - Handles the loop of displaying the prompt and reading input.
*/
void prompt_loop(void)
{
	char *line = NULL;

	size_t len = 0;
	ssize_t read;

	while (1)
	{
		display_prompt();
		read = my_getline(&line, &len);
		if (read == -1)
		{
			if (feof(stdin))
			{
				free(line);
				write(STDOUT_FILENO, "\n", 1);
				/* Print a newline for a clean exit on EOF */
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("readline");
				continue;
			}
		}

		line[strcspn(line, "\n")] = '\0'; /* Remove newline character */
		execute(line);
	}

	free(line);
}
