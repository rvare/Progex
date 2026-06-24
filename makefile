OBJFILES=./build/main.o ./build/check_mkdir_error.o ./build/create_c_project.o \
			./build/create_java_project.o ./build/create_directories.o ./build/create_files.o
CFLAGS=-c -Wall -Wswitch-default -Wconversion

default: $(OBJFILES)
	gcc -Wall $(OBJFILES) -o ./build/a.exe

./build/main.o: ./src/main.c
	gcc $(CFLAGS) ./src/main.c -o ./build/main.o

./build/create_directories.o: ./src/create_directories.c
	gcc $(CFLAGS) ./src/create_directories.c -o ./build/create_directories.o

./build/create_files.o: ./src/create_files.c
	gcc $(CFLAGS) ./src/create_files.c -o ./build/create_files.o

./build/check_mkdir_error.o: ./src/check_mkdir_error.c
	gcc $(CFLAGS) ./src/check_mkdir_error.c -o ./build/check_mkdir_error.o

./build/create_c_project.o: ./src/create_c_project.c
	gcc $(CFLAGS) ./src/create_c_project.c -o ./build/create_c_project.o

./build/create_java_project.o: ./src/create_java_project.c
	gcc $(CFLAGS) ./src/create_java_project.c -o ./build/create_java_project.o

test-c: ./build/a.exe
	./build/a.exe c ./tests/my_pro

test-java: ./build/a.exe
	./build/a.exe java my_java_pro

debug: $(OBJFILES)
	gcc -g ./src/*.c -o ./build/a.exe
	gdb --args ./build/a.exe c my_pro

clean:
	./build/*.o ./build/a.exe
