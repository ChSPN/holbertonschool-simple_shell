#include "shell.h"

/**
* execute_command - Executes a command with given path and args.
* @full_path: The full path to the executable.
* @args: Command arguments.
*
* Description: This function uses execve to run the command.
* If execve fails, it prints an error message and exits.
*/
void execute_command(char *full_path, char **args)
{
	execve(full_path, args, environ);
	perror("Execve failed");
	exit(1);
}

/**
* check_command_path - Resolves the path of a cmd using the PATH env var.
* @command_path: The command to be executed.
* @args: Command arguments.
*
* Description: Searches the PATH environment variable to find
* the full path of the command. If found, it executes the command.
* Otherwise, it prints an error message and exits.
*/
void check_command_path(char *command_path, char **args)
{
	char *path = getenv("PATH");

	char *path_value;

	char full_path[256]; /* Buffer to store the full path of the command */

	if (path == NULL)
	{
		fprintf(stderr, "PATH not set\n");
		exit(1);
	}

	/* Tokenize the PATH and construct full paths to check for the command */
	path_value = strtok(path, ":");
	while (path_value != NULL)
	{
		strcpy(full_path, path_value);
		strcat(full_path, "/");
		strcat(full_path, command_path);

		if (access(full_path, X_OK) == 0)
		{
			execute_command(full_path, args);
			return; /* Exit if command is successfully executed */
		}

		path_value = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: command not found\n", command_path);
	exit(1);
}

/**
* handle_child_process - Handles the child process execution logic.
* @command_path: The command to be executed.
* @args: Command arguments.
*
* Description: Decides how to execute the command based on whether
* it's an absolute path or needs path resolution.
*/
void handle_child_process(char *command_path, char **args)
{
	if (command_path[0] != '/') /* Not an absolute path */
	{
		check_command_path(command_path, args);
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
}

/**
* shell_execute - Executes commands provided by args.
* @args: An array of strings where the 1st is the cmd and the rest are params.
* Return: State of execution, 0 on success, -1 on error.
*
* Description: This function creates a child process to execute a command.
* It handles errors in forking and waits for the child process to complete.
*/
int shell_execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		free(args); /* Free args before returning on error */
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
		free(args); /* Free args after completion */
		return (0);
	}
}
