#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>  /* Includes declarations used by the shell */
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* Macros */
#define PROMPT "$ "

/* External environment variables */
extern char **environ;

/* Function prototypes */
void prompt_loop(void);
void execute(char *command);
void print_error(void);

#endif /* SHELL_H */
