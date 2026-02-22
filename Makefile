CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic
TARGET = note2_program

SRCS = main.c note2_server.c
OBJS = $(SRCS:.c=.o)
HEADERS = note2.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
