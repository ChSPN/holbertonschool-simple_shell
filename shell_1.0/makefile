# Compiler and compilation flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89

# Name of the final executable
EXEC := simple_shell

# Source files and object files
SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

# Default target
all: $(EXEC)

# Link object files into a binary
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets
.PHONY: all clean
