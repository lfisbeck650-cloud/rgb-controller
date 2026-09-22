CC = gcc

CFLAGS = $(shell pkg-config --cflags gtk+-3.0)
LIBS = $(shell pkg-config --libs gtk+-3.0)

TARGET = rgb-controller

all: $(TARGET)

$(TARGET): main.o rgb.o
	$(CC) main.o rgb.o -o $(TARGET) $(LIBS)

main.o: main.c rgb.h
	$(CC) $(CFLAGS) -c main.c

rgb.o: rgb.c rgb.h
	$(CC) -c rgb.c

clean:
	rm -f *.o $(TARGET)