OBJFILES=./build/main.o ./build/create_c_project.o
CFLAGS=-c -Wall

default: $(OBJFILES)
	gcc -Wall $(OBJFILES) -o ./build/a.exe

./build/main.o: ./src/main.c
	gcc $(CFLAGS) ./src/main.c -o ./build/main.o

./build/create_c_project.o: ./src/create_c_project.c
	gcc $(CFLAGS) ./src/create_c_project.c -o ./build/create_c_project.o

run:
	./build/a.exe c my_pro

clean:
	./build/*.o ./build/a.exe
