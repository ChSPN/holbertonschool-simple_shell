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
* check_command_path - Resolves the path of a cmd using the PATH env var.
* @command_path: The command to be executed.
* @args: Command arguments.
*
* Description: This function searches the PATH environment variable to find
* the full path of the command. If found, it executes the command using
* `execute_command` function. It returns true if the command is successfully
* executed or false if the command is not found in the PATH.
*
* Return: Returns 1 if the command is found and executed, otherwise 0.
*/
int check_command_path(char *command_path, char **args);

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

/**
* free_argv - simple free func
* @argv: Arg array
*/
void free_argv(char **argv);


/* Built-in functions */

/* builtins.h - Definitions for built-in shell commands */

/**
* struct builtin - Represents a built-in command for the shell
* @name: Name of the built-in command
* @func: Function pointer for executing the command
*
* Description: Associates a cmd name with a function that handles the command.
*/

typedef struct builtin
{
	char *name;             /* Name of the built-in command */

	int (*func)(char **);   /* Function pointer for the command */
} builtin_t;

/**
* get_builtins - Accessor for built-in commands array
*
* Return: Pointer to the first element of the array of built-in commands
*/
builtin_t *get_builtins(void);

/**
* builtin_exit - Exits the shell
* @args: Command arguments
*
* Return: Does not return, terminates the process
*/
int builtin_exit(char **args);

/**
* builtin_cd - Changes the current working directory of the shell
* @args: Command arguments, args[1] should be the new directory
*
* Return: 1 on success, 0 on failure
*/
int builtin_cd(char **args);

/**
* execute_external_command - Handles the execution of external commands.
* @args: Command arguments including the command itself.
*
* Description: Forks the process and executes the external command. The parent
* process waits for the completion of the child.
*
* Return: 0 on success, -1 on failure.
*/
int execute_external_command(char **args);

#endif

