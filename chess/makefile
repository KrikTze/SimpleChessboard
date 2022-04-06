CC= g++
CFLAGS =-c -Wall
SOURCES=main.cpp chessboard.cpp pieces.cpp tile.cpp
OBJECTS=$(SOURCES:.c=.o)
EXEC=chess

all:$(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXEC)