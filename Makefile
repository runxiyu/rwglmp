e: e.c lib/monocypher.o lib/monocypher.h
	$(CC) -o $@ e.c lib/monocypher.o

lib/monocypher.o: lib/monocypher.c
	$(CC) -c -o $@ lib/monocypher.c
