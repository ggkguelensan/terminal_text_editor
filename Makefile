P = kilo
OBJECTS = kilo.c
CC = gcc-9
CFALAGS = `` -Wall -Wextra -Werror -pedantic -g -std=gnu11
LDLIBS = ``

$(P): kilo.c
	$(CC) $(CFALAGS) -O2 $(OBJECTS) $(LDLIBS) -o $(P)