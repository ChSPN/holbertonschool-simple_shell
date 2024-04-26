#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h> /* Include for struct stat and stat() */
#include <errno.h>

#define MAX_ARGS 64
#define MAX_COMMAND_LENGTH 100
#define PROMPT "$cisfun "

extern char **environ; /* Use of global environment variable 'environ' */

/*Prototypes*/

/* in main.c */
int main(void);
void handle_command(char *command);
void handle_process(char *command);
char *initialize_command(void);

/* in spec files */
int executeCommand(char *command);
char **tokenizeCommand(char *input);
char *findCommandPath(char *input);
char *readCommand(void);

#endif
