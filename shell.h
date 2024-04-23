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

void handle_child_process(char *command_path, char **args);
void check_command_path(char *command_path, char **args);
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
* find_command_in_path - Searches for a command in the PATH env variable
* @command: The command to find in the PATH
* Return: Full path to the command if found, otherwise NULL
* Description: Iterates through dir listed in PATH to find the executable
*/
char *find_command_in_path(char *command);

#endif

