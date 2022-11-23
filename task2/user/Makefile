.PHONY: all clean

all: userland

userland: userland.c oracle.c
	$(CC) -O2 -o userland userland.c oracle.c

clean:
	$(RM) userland
