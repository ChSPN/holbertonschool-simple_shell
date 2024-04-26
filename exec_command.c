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
* initialize_path - Initializes and checks path
* @path_env: Environment path variable
* @path_copy: Buffer to hold the copy of path
* @path_copy_size: Size of the path_copy buffer
*
* Return: (0) if PATH is NULL, (1) otherwise
*/
int initialize_path(char **path_env, char *path_copy, size_t path_copy_size)
{
	*path_env = _getenv("PATH");
	if (*path_env == NULL)
	{
		return (0);
	}
	strncpy(path_copy, *path_env, path_copy_size - 1);
	path_copy[path_copy_size - 1] = '\0';
	return (1);
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
	char path_copy[1024], *path_env, *saveptr, *path_value;

	if (!initialize_path(&path_env, path_copy, sizeof(path_copy)))
	{
		return (0);
	}

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
* validate_command - Validates and processes the command
* @args: Command arguments
* @resolved_path: Buffer to store the executable path
*
* Return: (1) if command is valid, (-1) otherwise
*/
int validate_command(char **args, char *resolved_path)
{
	    if (strcmp(args[0], "exit") == 0)  /* Check for the "exit" command */
	{
		exit(0);  /* Exit the shell */
	}

	if (args[0][0] != '/' && !find_executable_path(args[0], resolved_path))
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (-1);
	}
	return (1);
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

	char resolved_path[256];

	if (validate_command(args, resolved_path) == -1)
	{
		return (-1);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return (-1);
	}

	if (pid == 0) /* Child process */
	{
		execute_command(args[0][0] != '/' ? resolved_path : args[0], args);
	}
	else /* Parent process */
	{
		while (waitpid(pid, &status, 0) != pid)
		{
			if (errno != EINTR)
			{
				perror("Waitpid failed");
				break;
			}
		}
	}
	return (0);
}
