e: e.c monocypher.o monocypher.h
	$(CC) -o $@ e.c monocypher.o

monocypher.o: monocypher.c
	$(CC) -c -o $@ monocypher.c
