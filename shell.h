#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 16

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
 * @argv: list of command
 * Return: state of execution
*/
int shell_execute(char *argv[]);

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

#endif
