CC = gcc
PROG = scanner

$(PROG): driver.o scanner.o
	$(CC) -o $(PROG) driver.o scanner.o

driver.o : driver.c token.h scanner.h
	$(CC) -c driver.c

scanner.o : scanner.c token.h scanner.h symdef.h
	$(CC) -c scanner.c

.PHONY: clean

clean:
	/usr/bin.rm -rf core $(PROG) *.o