TARGET=myproj
CC=gcc
CFLAGS=-g -Wall
OBJECTS=myproj.o mylib.o

all:$(TARGET)
clean:
	rm -f *.o $(TARGET) core
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(CFLAGS) $(OBJECTS)
.c.o:
	$(CC) -c $(CFLAGS) $<

myproj.o: mylib.h
