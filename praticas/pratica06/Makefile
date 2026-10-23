CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = programa
OBJ = main.o grafo.o

	all: $(TARGET)

	$(TARGET): $(OBJ)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

	main.o: main.c grafo.h
		$(CC) $(CFLAGS) -c main.c

	grafo.o: grafo.c grafo.h
		$(CC) $(CFLAGS) -c grafo.c

	clean:
		rm -f $(OBJ) $(TARGET)

.PHONY: all clean