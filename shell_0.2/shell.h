#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define PROMPT "$ "
#define MAX_ARGS 10

/* Function Prototypes */
int read_line(char *buffer, int size);
char **parse_command(char *command);
void execute_command(char **args);

#endif
