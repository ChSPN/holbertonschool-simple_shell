#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h> /* Include for struct stat and stat() */

#define MAX_ARGS 16
#define MAX_COMMAND_LENGTH 100
#define PROMPT "$cisfun "

/**
* struct execute - Struct to map identifier specifiers to their functions.
* @identifier: The action specifier.
* @ptr_execute: Pointer to the function that handles the execution for action.
* Description: This structure is used to associate format specifiers with
* the corresponding function that knows how to execution that action.
*/
typedef struct execute
{
	char *identifier;
	int (*ptr_execute)(char **);
} execute_t;

/**
 * shell_execute - Execute shell command
 * Description: Fonction to execute shell command
 * @args: list of command
 * Return: state of execution
*/
int shell_execute(char **args);

/**
 *  handle_child_process - Handle the child process after forking
 * @command_path: The path to the command to execute
 * @args: Array of strings representing the command arguments
 *
 * This function handles the execution of a child process after forking.
 * It takes the path to the command to execute and an array of strings
 * representing the command arguments.
 */
void handle_child_process(char *command_path, char **args);

/**
 *  check_command_path - Check if the command path is valid and executable
 * @command_path: The path to the command to execute
 * @args: Array of strings representing the command arguments
 *
 * This function checks if the specified command path is valid and executable.
 * It takes the path to the command to execute and an array of strings
 * representing the command arguments.
 */
void check_command_path(char *command_path, char **args);

/**
 *  execute_command - Execute the command with the specified arguments
 * @full_path: The full path to the command to execute
 * @args: Array of strings representing the command arguments
 *
 * This function executes the command with the specified full path
 * and arguments.
 */
void execute_command(char *full_path, char **args);


/**
 * get_argv - Get the arguments values
 * Description: Get the arguments values
 * @cmd: string of command
 * Return: Return the list of arguments
*/
char **get_argv(char cmd[]);

 /* Prototype that select & executes function for identifier. */
int (*get_execute_func(execute_t executes[], char *identifier))(char **);

/**
 * exit_execute - Execute the exit
 * Description: Execute the exit
 * @argv: list of command
 * Return: state of execution
*/
int exit_execute(char *argv[]);

/**
 * printenv_execute - Print the environments variables
 * Description: Print the environments variables
 * @argv: list of command
 * Return: state of execution
*/
int printenv_execute(char *argv[]);

/* The environments variables */
extern char **environ;

/**
* find_command_in_path - Searches for a command in the PATH env var
* @path: The PATH environment variable
* @command: The command to find in the PATH
* Return: Full path to the command if found, otherwise NULL
* Description: Iterates in directories listed in PATH to find the executable
*/
char *find_command_in_path(char *path, char *command);

/**
 * free_memory - Frees memory allocated for command arguments and path.
 *
 * @args: Double pointer to the array of command arguments.
 * @path: Pointer to the string representing the executable path.
 */

void free_memory(char **args, char *path);

#endif

