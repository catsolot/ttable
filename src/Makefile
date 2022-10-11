CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
LDFLAGS = 

SOURCES = main.c io.c logic.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = ttable

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY : clean

clean:
	rm -rf $(TARGET) $(OBJECTS) core
