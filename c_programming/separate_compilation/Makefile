# Makefile

CC = gcc
CFLAGS = -Wall -O
LDFLAGS = -lm

SRC1 = code1.c
SRC2 = code2.c
OBJS = $(SRC1:.c=.o) $(SRC2:.c=.o)
TARGET = code12

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET)
