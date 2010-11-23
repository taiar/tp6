CC = gcc
CFLAGS = -g -Wall -lm
BIN = tp6
XFLAGSA = -i entrada/in -o saida
SAIDAS = saida
RM = *.o *.h.gch $(BIN) $(SAIDAS)

io: io.c io.h
	$(CC) -c io.c io.h $(CFLAGS)
	
main: io
	$(CC) -o $(BIN) tp6.c io.o $(CFLAGS)

valgrind: clean main
	valgrind ./$(BIN) $(XFLAGSA)

all: main

clean:
	rm -rf $(RM)

run: clean main
	./$(BIN) $(XFLAGSA)