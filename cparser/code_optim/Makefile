CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =

# List of source files
SRCS = basic_block.c ../quadruples.c dag.c

# Generate a list of object files from source files
OBJS = $(SRCS:.c=.o)

# Name of the executable
TARGET = code_optim

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean

