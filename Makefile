P = kilo
OBJECTS = kilo.c terminal.c input.c output.c
CC = gcc-9
CFALAGS = -Wall -g -std=gnu11

$(P): $(OBJECTS)
	$(CC) $(CFALAGS) -O2 $(OBJECTS) $(LDLIBS) -o $(P)
	rm *.o