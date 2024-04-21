#include "shell.h"

/**
 * shell_execute - Execute shell command
 * Description: Fonction to execute shell command
 * @argv: list of command
*/
void shell_execute(char *argv[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		perror("Execve failed");
		exit(1);
	}
	else
	{
		if (waitpid(pid, &status, 0) != pid)
		{
			perror("Waitpid failed");
			exit(1);
		}
	}
}
