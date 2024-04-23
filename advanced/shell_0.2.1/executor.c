#include "shell.h"

void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		fprintf(stderr, "simple_shell: %s: command not found\n", args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("Child exited with status %d\n", WEXITSTATUS(status));
		}
	}
}
