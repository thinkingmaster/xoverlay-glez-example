.PHONY: clean

all: example

example.o: example.c
	gcc example.c -ggdb -g3 -c -o example.o

example: example.o
	gcc example.o -lxoverlay -lglez -o example

clean:
	rm -f *.o
	rm -f example