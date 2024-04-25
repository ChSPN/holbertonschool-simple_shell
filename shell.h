#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h> /* Include for struct stat and stat() */
#include <errno.h>

#define MAX_ARGS 16
#define MAX_COMMAND_LENGTH 100
#define PROMPT "$cisfun "

extern char **environ; /* Use of global environment variable 'environ' */


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
* shell_execute - Executes commands provided by args.
* @args: An array of strings where the 1st is the cmd and the rest are params.
* Return: State of execution, 0 on success, -1 on error.
*
* Description: This function creates a child process to execute a command.
* It handles errors in forking and waits for the child process to complete.
*/
int shell_execute(char **args);

/**
* handle_child_process - Handles the child process execution logic.
* @command_path: The command to be executed.
* @args: Command arguments.
*
* Description: Decides how to execute the command based on whether
* it's an absolute path or needs path resolution.
*/
void handle_child_process(char *command_path, char **args);

/**
* check_command_path - Resolves the path of a cmd using the PATH env variable.
* @command_path: The command to be executed.
* @args: Command arguments.
*
* Description: Searches the PATH environment variable to find
* the full path of the command. If found, it executes the command.
* Otherwise, it prints an error message and exits.
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

/* in env.c */

/**
* _getenv - Retrieves the value of an environment variable.
* @name: The name of the environment variable.
* Return: Pointer to the value part of the matched environment variable string.
*/
char *_getenv(const char *name);

/* in strings.c */

char *_strtok_r(char *str, const char *delim, char **saveptr);

/* in exec_commands.c */

void execute_command(char *full_path, char **args);
int initialize_path(char **path_env, char *path_copy, size_t path_copy_size);
int find_executable_path(char *command, char *resolved_path);
int validate_command(char **args, char *resolved_path);
int shell_execute(char **args);

#endif

