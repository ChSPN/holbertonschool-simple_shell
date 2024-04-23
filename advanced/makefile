# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Output directory for executables
BIN_DIR = .

# Define all executables
EXE = $(BIN_DIR)/_0.1.1

# Default target
all: $(EXE)

# Shell version 0.1.1 compilation
$(EXE): shell_0.1.1/_getline.c shell_0.1.1/errors.c shell_0.1.1/execute.c shell_0.1.1/main.c shell_0.1.1/prompt.c
	$(CC) $(CFLAGS) -o $@ $^

# Clean the built executables
clean:
	rm -f $(EXE)
