OBJFILES=./build/main.o
CFLAGS=-c -Wall

default: $(OBJFILES)
	gcc -Wall $(OBJFILES) -o ./build/a.exe

./build/main.o: ./src/main.c
	gcc $(CFLAGS) ./src/main.c -o ./build/main.o

run:
	./build/a.exe

clean:
	./build/*.o ./build/a.exe
