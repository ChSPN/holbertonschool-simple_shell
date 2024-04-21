CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# List of source files common across all versions
SRC_0_1 = shell_execute.c get_execute_func.c
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
EXECUTABLE_0_1 = hsh_0.1
EXECUTABLE_0_2 = hsh_0.2
EXECUTABLE_0_3 = hsh_0.3
EXECUTABLE_0_4 = hsh_0.4
EXECUTABLE_1_0 = hsh_1.0

all: $(EXECUTABLE_0_1) $(EXECUTABLE_0_2) $(EXECUTABLE_0_3) $(EXECUTABLE_0_4) $(EXECUTABLE_1_0)

$(EXECUTABLE_0_1): $(SRC_0_1) $(VERSION_0_1_SRCS)
	$(CC) $(CFLAGS) $(SRC_0_1)  $(VERSION_0_1_SRCS) -o $@

$(EXECUTABLE_0_2): $(SRC_0_2)  $(VERSION_0_2_SRCS)
	$(CC) $(CFLAGS) $(SRC_0_2)  $(VERSION_0_2_SRCS) -o $@

$(EXECUTABLE_0_3): $(SRC_0_3) $(VERSION_0_3_SRCS)
	$(CC) $(CFLAGS) $(SRC_0_3)  $(VERSION_0_3_SRCS) -o $@

$(EXECUTABLE_0_4): $(SRC_0_4)  $(VERSION_0_4_SRCS)
	$(CC) $(CFLAGS) $(SRC_0_4)  $(VERSION_0_4_SRCS) -o $@

$(EXECUTABLE_1_0): $(SRC_1_0)  $(VERSION_1_0_SRCS)
	$(CC) $(CFLAGS) $(SRC_1_0)  $(VERSION_1_0_SRCS) -o $@

clean:
	rm -f $(EXECUTABLE_0_1) $(EXECUTABLE_0_2) $(EXECUTABLE_0_3) $(EXECUTABLE_0_4) $(EXECUTABLE_1_0)
