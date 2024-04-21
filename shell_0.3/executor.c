#include "shell.h"

/**
* execute_command - Executes commands provided by args
* @args: An array of strings where the first is the command and the rest are parameters
* Description: If args[0] starts with '/', it's an absolute path and is executed directly.
* Otherwise, tries to resolve it using the PATH environment variable.
*/
void execute_command(char **args)
{
	pid_t pid;
	char *command_path;

	int status;

	/* Check if the command starts with '/' indicating it is an absolute path */
	if (args[0][0] == '/')
	{
		command_path = args[0];
		if (access(command_path, X_OK) != 0)
		{
			fprintf(stderr, "simple_shell: %s: No such file or directory\n", command_path);
			return; /* Command cannot be executed, return early */
		}
	}
	else
	{
		/* Resolve the command through PATH */
		command_path = find_command_in_path(args[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "simple_shell: %s: command not found\n", args[0]);
			return; /* Command cannot be executed, return early */
		}
	}

	/* Create a child process to execute the command */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		/* Child process: attempt to execute the command */
		execv(command_path, args);
		fprintf(stderr, "simple_shell: %s: failed to execute\n", command_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process: wait for the child to finish */
		waitpid(pid, &status, 0);
		if (command_path != args[0])
		{
			free(command_path); /* Free the memory if allocated by find_command_in_path */
		}
	}
}
