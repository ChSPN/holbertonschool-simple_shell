#include "shell.h"

/**
 * main - Entry point of simple_shell that uses getline for input
 * @arg: No arguments are handled in this shell version
 * Return: Returns 0 on successful execution, exits with 1 on error
 */
int main(void)
{
    char *cmd = NULL;
    size_t len = 0;
    ssize_t nread;
    pid_t pid;
    int status;

    while (1)
    {
        printf(PROMPT);
        nread = getline(&cmd, &len, stdin);
        if (nread == -1)
        {
            free(cmd);
            printf("\n");
            break; /* EOF received, exit the shell */
        }

        if (cmd[nread - 1] == '\n')
        {
            cmd[nread - 1] = '\0'; /* Remove the newline character */
        }

        if (strlen(cmd) == 0)
        {
            continue; /* Empty command, display prompt again */
        }

        pid = fork();
        if (pid == -1)
        {
            perror("Error:");
            continue;
        }
        if (pid == 0)
        {
            /* Child process */
            char *argv[2]; /* Declare argv without initializer */
            argv[0] = cmd; /* Set first element to cmd */
            argv[1] = NULL; /* Set second element to NULL */

            if (execve(cmd, argv, environ) == -1)
            {
                perror("Error:");
                exit(EXIT_FAILURE); /* If execve fails, exit the child */
            }
        }
        else
        {
            /* Parent process */
            waitpid(pid, &status, 0); /* Wait for the child to complete */
        }
    }

    return 0;
}
