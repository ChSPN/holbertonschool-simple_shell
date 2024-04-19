CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
TARGETS = myppid mypid prompt exec fork wait shell printenv

all: $(TARGETS)

mypid: pid.c
	$(CC) $(CFLAGS) pid.c -o mypid

myppid: 0.getppid.c
	$(CC) $(CFLAGS) 0.getppid.c -o myppid

prompt: prompt.c
	$(CC) $(CFLAGS) prompt.c -o prompt

exec: exec.c
	$(CC) $(CFLAGS) exec.c -o exec

fork: fork.c
	$(CC) $(CFLAGS) fork.c -o fork

wait: wait.c
	$(CC) $(CFLAGS) wait.c -o wait

shell: shell.c
	$(CC) $(CFLAGS) shell.c -o shell

printenv: env-main.c
	$(CC) $(CFLAGS) env-main.c -o printenv

clean:
	rm -f $(TARGETS)
