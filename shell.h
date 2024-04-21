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

#endif
