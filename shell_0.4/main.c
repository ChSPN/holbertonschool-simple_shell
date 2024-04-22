#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * main - Entry point of the simple shell
 * Description: Runs a loop that continually reads commands from the user,
 *              parses them, checks for the 'exit' built-in command, executes other commands,
 *              and manages memory appropriately to prevent leaks and errors.
 * Return: Returns EXIT_SUCCESS upon successful termination of the shell.
 */
int main(void)
{
    char command[MAX_COMMAND_LENGTH]; /* Buffer to hold the command entered by the user */
    char **args;                      /* Array to hold the parsed command and its arguments */
    int i;

    while (1)
    {
        /* Display the shell prompt */
        printf(PROMPT);
        fflush(stdout);

        /* Read a line of input from the user */
        if (read_line(command, MAX_COMMAND_LENGTH) == -1)
        {
            printf("\n"); /* Print a newline on EOF (Ctrl+D) */
            break;        /* Exit the loop on EOF */
        }

        if (strlen(command) == 0)
        {
            continue; /* Ignore empty commands and loop again */
        }

        /* Parse the command line into arguments */
        args = parse_command(command);
        if (args == NULL || args[0] == NULL)
        {
            free(args);
            continue; /* Handle parsing errors or empty args */
        }

        /* Handle the 'exit' built-in command */
        if (strcmp(args[0], "exit") == 0)
        {
            for (i = 0; args[i] != NULL; i++)
            {
                free(args[i]); /* Free each argument */
            }
            free(args); /* Free the argument array */
            break;      /* Break the loop and exit the shell */
        }

        /* Execute the command if it's not 'exit' */
        execute_command(args);

        /* Free memory allocated for the arguments after command execution */
        for (i = 0; args[i] != NULL; i++)
        {
            free(args[i]); /* Free each argument */
        }
        free(args);
    }

    return (EXIT_SUCCESS); /* Return success code from main */
}
