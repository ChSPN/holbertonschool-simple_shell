#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* struct path - Struct PATH variable
* @value: The value of the directory path
* @next: Pointer to the next node in the linked list
*/
typedef struct path
{
	char *value;
	struct path *next;
} path_t;

/*PROTOTYPES*/
/*0-printenv-environ.c*/


/*1-envp_vs_environ.c*/


/*2-getenv.c*/
char *_getenv(const char *name);

/*3-print-path.c*/
void printpath(void);

/*4-list-path.c*/
path_t *getpath(void);

/*5-set-env.c*/
int _setenv(const char *name, const char *value, int overwrite);

/*6-unsetenv.c*/
int _unsetenv(const char *name);


/*AUTRES*/

extern char **environ;

#endif
