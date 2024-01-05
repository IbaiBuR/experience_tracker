CCC = gcc
CFLAGS = -Wall -I.
LDFLAGS = -lncurses

all: experience_tracker

experience_tracker: main.o experience.o util.o
	$(CC) -o experience_tracker main.o experience.o util.o $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

experience.o: experience.c
	$(CC) $(CFLAGS) -c experience.c

util.o: util.c
	$(CC) $(CFLAGS) -c util.c

.PHONY: clean
clean:
	rm -rf *.o /readable_exp