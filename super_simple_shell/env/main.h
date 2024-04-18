#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

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

#endif
