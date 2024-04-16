# SUPER SIMPLE SHELL


## Objective 
**Super simple shell** is introduction project, composed by some tasks to introduce the Simple shell project.


## List of tasks
### PID & PPID
0. **getppid :** Write a program that prints the PID of the parent process. Run your program several times within the same shell. It should be the same. Does echo $$ print the same value? Why?
1. **/proc/sys/kernel/pid_max :** Write a shell script that prints the maximum value a process ID can be.

### Arguments
0. **av :** Write a program that prints all the arguments, without using ac.
1. **Read line :** Write a program that prints "$ ", wait for the user to enter a command, prints it on the next line.
1. **BIS : #advanced:** Write your own version of getline.
2. **command line to av :** Write a function that splits a string and returns an array of each word of the string.
2. **BIS : #advanced:** Write the function without strtok.

### Executing a program /Creating processes /Wait
Write a program that executes the command ls -l /tmp in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.

### Super simple shell
Using everything we saw, write a first version of a super simple shell that can run commands with their full path, without any argument.

### File information
Write a program that looks for files in the current PATH.

### Environment
0. **printenv with environ :** Write a program that prints the environment using the global variable environ.
1. **env vs environ :** Write a program that prints the address of env (the third parameter of the main function) and environ (the global variable). Are they they same? Does this make sense?
2. **getenv() :** Write a function that gets an environment variable. (without using getenv).
3. **PATH :** Write a function that prints each directory contained in the the environment variable PATH, one directory per line.
4. **PATH :** Write a function that builds a linked list of the PATH directories.
5. **setenv :** Write a function that changes or adds an environment variable (without using setenv).
6. **unsetenv :** Write a function that deletes the variable name from the environment (without using unsetenv).


## Environment
Ubuntu 20.04 LTS.


## Coding Style
Betty style for both coding and documentation.


## AUTHORIZED FUNCTIONS AND MACROS
/*??*/


## USAGE INSTRUCTIONS
### Compilation commands
- **PID & PPID :** *getppid.c* : `gcc -Wall -Werror -pedantic getppid.c -o mypid && ./mypid`
- **Executing a program /Creating processes /Wait** : *Execute Ls-l command* : `gcc -Wall -Werror -pedantic ls_command.c -o ls_command`
/*AUTRES GCC PAR ANTONIN*/

## Technologies
**development environment :** Visual Studio Code with Windows 11, compiled with Ubuntu on WSL & /*ANTONIN*/
**framework :** C programm & libraries : stdio ; stdlib ; unistd ; sys/wait ; sys/types. /*A COMPLETER ANTONIN*/

## REQUIREMENTS
[??]

## CONTRIBUTIONS
- [Antonin NOYELLE](https://github.com/Ninotna) - Initial work & contributions.
- [Charlène SCOMPARIN](https://github.com/ChSPN) - Initial work & contributions.


A METTRE A JOUR AVEC TACHES D'ANTONIN & SUPER SIMPLE SHELL