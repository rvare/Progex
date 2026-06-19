OBJFILES=./build/main.o ./build/check_mkdir_error.o ./build/create_c_project.o
CFLAGS=-c -Wall -Wswitch-default -Wconversion

default: $(OBJFILES)
	gcc -Wall $(OBJFILES) -o ./build/a.exe

./build/main.o: ./src/main.c
	gcc $(CFLAGS) ./src/main.c -o ./build/main.o

./build/check_mkdir_error.o: ./src/check_mkdir_error.c
	gcc $(CFLAGS) ./src/check_mkdir_error.c -o ./build/check_mkdir_error.o

./build/create_c_project.o: ./src/create_c_project.c
	gcc $(CFLAGS) ./src/create_c_project.c -o ./build/create_c_project.o

test-c: ./build/a.exe
	./build/a.exe c ./tests/my_pro

clean:
	./build/*.o ./build/a.exe
