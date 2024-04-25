#include "shell.h"

/**
* execute_command - Executes a command with given path and args
* @full_path: The full path to the executable
* @args: Command arguments
*
* Return: This function does not return
*/
void execute_command(char *full_path, char **args)
{
	execve(full_path, args, environ);
	perror("Execve failed");
	exit(1);
}

/**
* find_executable_path - Determines if a command exists and finds its path
* @command: The command to be executed
* @resolved_path: Buffer to store the resolved path if command exists
*
* Return: (1) if command is found and executable, (0) otherwise
*/
int find_executable_path(char *command, char *resolved_path)
{
	char *path_env;

	char path_copy[1024];

	char *saveptr;

	char *path_value;

	path_env = _getenv("PATH");
	if (path_env == NULL)
	{
		return (0);
	}

	/* Make a copy of the PATH env to avoid modifying the original */
	strncpy(path_copy, path_env, sizeof(path_copy) - 1);
	path_copy[sizeof(path_copy) - 1] = '\0';

	path_value = _strtok_r(path_copy, ":", &saveptr);
	while (path_value != NULL)
	{
		snprintf(resolved_path, 256, "%s/%s", path_value, command);
		if (access(resolved_path, X_OK) == 0)
		{
			return (1);
		}
		path_value = _strtok_r(NULL, ":", &saveptr);
	}

	return (0);
}

/**
* handle_child_process - Handles the child process execution logic
* @command_path: The command to be executed
* @args: Command arguments
*
* Return: None
*/
void handle_child_process(char *command_path, char **args)
{
	char resolved_path[256];

	if (command_path[0] != '/') /* Not an absolute path */
	{
		if (find_executable_path(command_path, resolved_path))
		{
			execute_command(resolved_path, args);
		}
		else
		{
			fprintf(stderr, "%s: command not found\n", command_path);
			exit(1);
		}
	}
	else if (access(command_path, X_OK) == 0) /* Absolute path is executable */
	{
		execute_command(command_path, args);
	}
	else
	{
		fprintf(stderr, "%s: command not found\n", command_path);
		exit(1);
	}
	free(args);
}

/**
* shell_execute - Executes commands provided by args
* @args: An array of strings where the 1st is the cmd and the rest are params
*
* Return: State of execution, 0 on success, -1 on error
*/
int shell_execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		free(args); /* Free args before returning */
		return (-1);
	}
	if (pid == 0)
	{
		handle_child_process(args[0], args); /* Child process handling */
		exit(0); /* Exit explicitly after handling */
	}
	else
	{
		/* Parent process waits for the child to complete */
		while (waitpid(pid, &status, 0) != pid)
		{
			if (errno != EINTR)
			{
				perror("Waitpid failed");
				break;
			}
		}
	}
	free(args); /* Free args after completion */
	return (0);
}
