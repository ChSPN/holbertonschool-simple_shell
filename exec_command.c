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
* the full path of the command. If found and executable, it executes the cmd.
* Returns 1 if the command is found and executed, otherwise 0.
*
* Return: Returns 1 if the command is found and executed, otherwise 0.
*/
int check_command_path(char *command_path, char **args)
{
	char *path = getenv("PATH");

	char *path_value;

	char full_path[256];

	if (path == NULL)
	{
		return (0);
	}

	path_value = strtok(path, ":");
	while (path_value != NULL)
	{
		strcpy(full_path, path_value);
		strcat(full_path, "/");
		strcat(full_path, command_path);

		if (access(full_path, X_OK) == 0)
		{
			execute_command(full_path, args);
			return (1); /* Command exists and was executed */
		}

		path_value = strtok(NULL, ":");
	}

	return (0); /* Command does not exist */
}

/**
* handle_child_process - Handles the child process execution logic.
* @command_path: The command to be executed.
* @args: Command arguments.
*
* Description: Decides how to execute the command based on whether
* it's an absolute path or needs path resolution. It prints "command not found"
* error once if the command does not exist.
*/
void handle_child_process(char *command_path, char **args)
{
	if (command_path[0] != '/')
	{
		if (!check_command_path(command_path, args)) /* Check if command exists */
		{
			fprintf(stderr, "%s: command not found\n", command_path);
			exit(1);
		}
	}
	else if (access(command_path, X_OK) != 0) /* Check if abs path is not exec */
	{
		fprintf(stderr, "%s: command not found\n", command_path);
		exit(1);
	}

	execute_command(command_path, args);
}


/**
* shell_execute - Executes commands provided by args.
* @args: An array of strings where the first is the cmd and the rest are params
* Description: This function orchestrates the execution of a command
* by first checking if it is a built-in command. If it is, the corresponding
* built-in function is executed. If not, it proceeds to create a child process
* to execute the command externally. It handles errors in forking and waits
* for the child process to complete.
*
* Return: Returns 0 if the command execution completes successfully, -1 if
* there is an error with forking or if waiting for the child process fails.
*/
int shell_execute(char **args)
{
	builtin_t *builtins;
	int i;

	if (args[0] == NULL)
	{
		return (0);  /* No command entered. */
	}

	builtins = get_builtins();  /* Retrieve the array of built-in commands */

	/* Check for built-in commands first */
	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			return (builtins[i].func(args));  /* Execute the matched built-in function*/
		}
	}

	/* If command is not built-in, execute it as an external command */
	return (execute_external_command(args));
}

/**
* execute_external_command - Handles the execution of external commands.
* @args: Command arguments including the command itself.
*
* Description: Forks the process and executes the external command. The parent
* process waits for the completion of the child.
*
* Return: 0 on success, -1 on failure.
*/
int execute_external_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		return (-1);
	} else if (pid == 0)
	{
		/* Child process: execute the command */
		if (execvp(args[0], args) == -1)
		{
			perror("Execution failed");
			exit(EXIT_FAILURE);
		}
	} else
	{
		/* Parent process: wait for the child to finish */
		while (waitpid(pid, &status, 0) != pid)
		{
			if (errno != EINTR)
			{
				perror("Wait failed");
				return (-1);
			}
		}
	}
	return (0);
}
