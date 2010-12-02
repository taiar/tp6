CC = gcc
CFLAGS = -g -Wall -lm
BIN = tp6
XFLAGSA = -i entrada/ex1 -o saida
SAIDAS = saida*
RM = *.o *.h.gch $(BIN) $(SAIDAS)

io: io.c io.h
	$(CC) -c io.c io.h $(CFLAGS)
	
stop: stopWords.c stopWords.h
	$(CC) -c stopWords.c stopWords.h $(CFLAGS)
	
exp: expressoes.c expressoes.h
	$(CC) -c expressoes.c expressoes.h $(CFLAGS)

et1: etapa1.c etapa1.h
	$(CC) -c etapa1.c etapa1.h $(CFLAGS)

et3: etapa3.c etapa3.h
	$(CC) -c etapa3.c etapa3.h $(CFLAGS)

main: io stop exp et1 et3
	$(CC) -o $(BIN) tp6.c io.o stopWords.o expressoes.o etapa1.o etapa3.o $(CFLAGS)

valgrind: clean main
	valgrind ./$(BIN) $(XFLAGSA)

all: main

clean:
	rm -rf $(RM)

run: clean main
	./$(BIN) $(XFLAGSA)
