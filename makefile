CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# List of source files common across all versions
SRC_0_1 = shell_execute.c
SRC_0_2 = shell_execute.c get_argv.c
SRC_0_3 = shell_execute.c get_argv.c
SRC_0_4 = shell_execute.c get_argv.c get_execute_func.c exit_execute.c
SRC_1_0 = shell_execute.c get_argv.c get_execute_func.c printenv_execute.c exit_execute.c

# List of version-specific source files
VERSION_0_1_SRCS = shell_0.1.c
VERSION_0_2_SRCS = shell_0.2.c
VERSION_0_3_SRCS = shell_0.3.c
VERSION_0_4_SRCS = shell_0.4.c
VERSION_0_4_SRCS = shell_1_0.c

# List of executables with corresponding source files
0_1 = hsh_0.1
0_2 = hsh_0.2
0_3 = hsh_0.3
0_4 = hsh_0.4
1_0 = hsh_1.0

all: $(0_1) $(0_2) $(0_3) $(0_4) $(1_0)

$(0_1): $(SRC_0_1) $(VERSION_0_1_SRCS)
	$(CC) $(CFLAGS) $(SRC_0_1)  $(VERSION_0_1_SRCS) -o $@

$(0_2): $(SRC_0_2)  $(VERSION_0_2_SRCS)
	$(CC) $(CFLAGS) $(SRC_0_2)  $(VERSION_0_2_SRCS) -o $@

$(0_3): $(SRC_0_3) $(VERSION_0_3_SRCS)
	$(CC) $(CFLAGS) $(SRC_0_3)  $(VERSION_0_3_SRCS) -o $@

$(0_4): $(SRC_0_4)  $(VERSION_0_4_SRCS)
	$(CC) $(CFLAGS) $(SRC_0_4)  $(VERSION_0_4_SRCS) -o $@

$(1_0): $(SRC_1_0)  $(VERSION_1_0_SRCS)
	$(CC) $(CFLAGS) $(SRC_1_0)  $(VERSION_1_0_SRCS) -o $@

clean:
	rm -f $(0_1) $(0_2) $(0_3) $(0_4) $(1_0)
