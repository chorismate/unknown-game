CC      := cc
CCFLAGS := -O3 -Weverything -pedantic

unknown:
	$(CC) $(CCFLAGS) delays.c randomization.c theoutset.c main.c -o unknown-game

clean:
	rm -f *.o