# SIMPLE SHELL


## Objective 
**Simple shell** is (à completer)


## List of  mantory tasks
0. **README, man, AUTHORS :** Write a README . Write a man for your shell. You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. 
1. **Betty would be proud :** Write a beautiful code that passes the Betty checks.
2. **Simple shell 0.1 :** Write a UNIX command line interpreter.
3. **Simple shell 0.2 :** Simple shell 0.1 + Handle command lines with arguments.
4. **Simple shell 0.3 :** Simple shell 0.2 + Handle the PATH + fork must not be called if the command doesn’t exist.
5. **Simple shell 0.4 :** Simple shell 0.3 + Implement the exit built-in, that exits the shell + Usage: exit + You don’t have to handle any argument to the built-in exit.
6. **Simple shell 1.0 :** Simple shell 0.4 + Implement the env built-in, that prints the current environment.

## List of advanced tasks
7. **What happens when you type `ls -l *.c` in the shell :** Write a blog post describing step by step what happens when you type ls -l *.c and hit Enter in a shell. Try to explain every step you know of, going in as much details as you can, give examples and draw diagrams when needed. You should merge your previous knowledge of the shell with the specifics of how it works under the hoods (including syscalls).
8. **Test suite :** Contribute to a test suite for your shell.
9. **Simple shell 0.1.1 :** Simple shell 0.1 + Write your own getline function + Use a buffer to read many chars at once and call the least possible the read system call + You will need to use static variables + You are not allowed to use getline.
10. **Simple shell 0.2.1 :** Simple shell 0.2 + You are not allowed to use strtok.
11. **Simple shell 0.4.1 :** Simple shell 0.4 + handle arguments for the built-in exit + Usage: exit status, where status is an integer used to exit the shell.
12. **Simple shell 0.4.2 :** Simple shell 0.4 + Handle Ctrl+C: your shell should not quit when the user inputs ^C.
13. **setenv, unsetenv :** Simple shell 1.0 + Implement the setenv and unsetenv builtin commands.
14. **cd :** Simple shell 1.0 + Implement the builtin command cd.
15. **; :** Simple shell 1.0 + Handle the commands separator ;.
16. **&& and || :** Simple shell 1.0 + Handle the && and || shell logical operators.
17. **Alias :** Simple shell 1.0 + Implement the alias builtin command.
18. **Variables :** Simple shell 1.0 + Handle variables replacement + Handle the $? variable + Handle the $$ variable.
19. **Comments :** Simple shell 1.0 + Handle comments (#).
20. **Help :** Simple shell 1.0 + Implement the help built-in.
21. **History :** Simple shell 1.0 + Implement the history built-in, without any argument.
22. **File as input :** Simple shell 1.0 + Your shell can take a file as a command line argument + The file contains all the commands that your shell should run before exiting + The file should contain one command per line + In this mode, the shell should not print a prompt and should not read from stdin.


## AUTHORIZED FUNCTIONS AND MACROS
/*??*/


## USAGE INSTRUCTIONS
### Compilation commands /*OK*/
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### Testing
**Interactive mode**
présent dans la consigne

**Non interactive mode**
present dans la consigne

### Checks
**Coding Style**
Betty style for both coding and documentation.


## Technologies
- **Environment :** Ubuntu 20.04 LTS.
- **development environment :** Visual Studio Code with Windows 11, compiled with Ubuntu on WSL & /*ANTONIN*/
- **framework :** C programm & libraries : stdio ; stdlib ; unistd ; sys/wait ; sys/types. /*A COMPLETER ANTONIN*/

## REQUIREMENTS
[??]

## CONTRIBUTIONS
- [Antonin NOYELLE](https://github.com/Ninotna) - Initial work & contributions.
- [Charlène SCOMPARIN](https://github.com/ChSPN) - Initial work & contributions.