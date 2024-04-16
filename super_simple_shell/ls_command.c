#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
* main - execute "ls-l /tmp".
* Description: Write a C program spawning 5 child processes,
* each executing "ls -l /tmp".
* The parent waits for each child to finish before creating a new one.
* Return: (0)
*/

int main(void)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		pid_t pid = fork();

		if (pid < 0)
		{
			/* Fork failed*/
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/* Child process*/
			char *args[] = {"ls", "-l", "/tmp", NULL};

			execve("/bin/ls", args, NULL);
			/* If execve fails*/
			perror("execve");
			exit(EXIT_FAILURE);

		}

		else
		{
			/* Parent process*/
			int status;

			wait(&status); /* Wait for child to exit*/
		}
	}

	return (0);
}
