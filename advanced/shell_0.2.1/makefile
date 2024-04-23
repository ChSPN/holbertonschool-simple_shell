CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=gnu89

TARGET := simple_shell
SRCS := main.c input.c parser.c executor.c
OBJS := $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
