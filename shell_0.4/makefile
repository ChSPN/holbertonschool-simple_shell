# Compiler settings
CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89

# Target executable
TARGET := simple_shell

# Source files
SRCS := main.c input.c parser.c executor.c path_resolver.c

# Object files
OBJS := $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Generic rule for compiling source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the compiled files
clean:
	rm -f $(TARGET) $(OBJS)

# Declare phony targets
.PHONY: all clean
