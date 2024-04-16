#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

/**
* getppid - returns the parent process ID.
* Description: getppid result remains constant; parent process execute program.
* Return: (0)
*/

int main(void)
{
	pid_t ppid = getppid();

	printf("%u\n", ppid);
	return (0);
}

