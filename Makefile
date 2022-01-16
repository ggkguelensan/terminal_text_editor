P = kilo
OBJECTS = kilo.c terminal.c input.c output.c error_handling.c
CC = gcc-9
CFALAGS = -Wall -Wextra -Werror -pedantic -g -std=gnu11

$(P): $(OBJECTS)
	$(CC) $(CFALAGS) -O2 $(OBJECTS) $(LDLIBS) -o $(P)