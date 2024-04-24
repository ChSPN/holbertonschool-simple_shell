#include "shell.h"

/**
* execute_command - Executes a command with given path and args
* @full_path: The full path to the executable
* @args: Command arguments
*/
void execute_command(char *full_path, char **args)
{
	execve(full_path, args, environ);
	perror("Execve failed");
	exit(1);
}

/**
* check_command_path - Resolves the path of a cmd using PATH env variable
* @command_path: The command to be executed
* @args: Command arguments
*/
void check_command_path(char *command_path, char **args)
{
	char *path = getenv("PATH");

	char *path_value = strtok(path, ":");

	char full_path[256];

	while (path_value != NULL)
	{
		strcpy(full_path, path_value);
		strcat(full_path, "/");
		strcat(full_path, command_path);

		if (access(full_path, X_OK) == 0)
		{
			execute_command(full_path, args);
		}

		path_value = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: command not found\n", command_path);
	exit(1);
}

/**
* handle_child_process - Handles the child process execution logic
* @command_path: The command to be executed
* @args: Command arguments
*/
void handle_child_process(char *command_path, char **args)
{
	if (command_path[0] != '/') /* Not an absolute path */
	{
		check_command_path(command_path, args);
	}
	else if (access(command_path, X_OK) == 0) /* Absolute path */
	{
		execute_command(command_path, args);
	}
	else
	{
		fprintf(stderr, "%s: command not found\n", command_path);
		exit(1);
	}
	free_memory(args, NULL); /* Free args only */
}


/**
* shell_execute - Executes commands provided by args
* If args[0] starts with '/', it's an abs path and is executed directly.
* Otherwise, tries to resolve it using the PATH environment variable.
* @args: An array of strings where the 1st is the cmd and the rest are params
* Return: state of execution
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
	}
	else
	{
		if (waitpid(pid, &status, 0) != pid)
		{
			perror("Waitpid failed");
			free(args); /* Free args on parent side if wait fails */
			return (-1);
		}
	}
	free(args); /* Free args after wait succeeds */
	return (0);
}
