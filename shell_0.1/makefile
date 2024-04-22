# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

# Name of the executable output
OUTPUT = simple_shell

# Source files
SOURCES = main.c execute.c prompt.c errors.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(OUTPUT)

# Rule to link the program
$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Rule to compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the build
clean:
	rm
