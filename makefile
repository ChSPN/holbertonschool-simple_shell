CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

EXECS = 0_1 0_2 0_3 0_4 1_0

# Default target
all: $(EXECS)

# Compilation rules for each executable
0_1: shell_execute.c shell_0.1.c
	$(CC) $(CFLAGS) $^ -o $@

0_2: shell_execute.c get_argv.c shell_0.2.c
	$(CC) $(CFLAGS) $^ -o $@

0_3: shell_execute.c get_argv.c shell_0.3.c
	$(CC) $(CFLAGS) $^ -o $@

0_4: shell_execute.c get_argv.c get_execute_func.c exit_execute.c shell_0.4.c
	$(CC) $(CFLAGS) $^ -o $@

1_0: shell_execute.c get_argv.c get_execute_func.c exit_execute.c printenv_execute.c shell_1.0.c
	$(CC) $(CFLAGS) $^ -o $@

# Clean target
clean:
	rm -f $(EXECS)
