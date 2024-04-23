#include "shell.h"

/**
* execute - Executes a command.
* @command: Command to execute.
*/
void execute(char *command)
{
	pid_t pid;
	int status;

	char *argv[] = {command, NULL};

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(command, argv, environ) == -1)
		{
			print_error();
			_exit(EXIT_FAILURE);
			/* Use _exit to ensure immediate termination in child */
		}
	}
	else if (pid < 0)
	{
		/* Forking error */
		perror("Error forking");
	}
	else
	{
		/* Parent process */
		while (waitpid(pid, &status, WUNTRACED)
		&& !WIFEXITED(status) && !WIFSIGNALED(status))
		;
	}
}
