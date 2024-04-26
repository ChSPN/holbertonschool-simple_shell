#include "shell.h"

/**
* handle_command - Handles the execution of commands
* @command: command to be processed
* Return: void
*/
void handle_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	handle_process(command);
}

/**
* handle_process - Manages child processes
* @command: command to be executed in child process
* Return: void
*/
void handle_process(char *command)
{
	int status;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
	}
	else if (pid == 0)
	{
		executeCommand(command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
* initialize_command - Initializes command reading and trimming
* Return: trimmed command
*/
char *initialize_command(void)
{
	char *command = readCommand();

	char *command_start = command;

	if (command == NULL || command[0] == '\n' || command[0] == '\0')
	{
		free(command_start);
		return (NULL);
	}
	while (command[0] == ' ' || command[0] == '\t')
	{
		command++;
	}
	return (command);
}

/**
* main - Entry point for the simple shell
* Return: Always returns 0
*/
int main(void)
{
	char *command;

	while (1)
	{
		command = initialize_command();
		if (command != NULL)
		{
			handle_command(command);
		}
	}
	return (0);
}
