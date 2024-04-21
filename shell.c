#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 1

/**
 * main - simple shell function
 * Description: simple shell function
 * Return: state of simple shell execution
*/
int main(void)
{
	char cmd[MAX_CMD_LEN];
	char *argv[MAX_ARGS];
	pid_t pid;
	int status;
	char *args[] = { NULL };

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(cmd, sizeof(cmd), stdin) == NULL)
		{
			printf("\n");
			exit(0);
		}
		cmd[strlen(cmd) - 1] = '\0';
		argv[0] = strtok(cmd, " ");
		pid = fork();
		if (pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		if (pid == 0)
		{
			execve(argv[0], args, NULL);
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
	return (0);
}
