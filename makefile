# Copyright (c) 2026 Richard Varela
# This file is part of Progex which is release under 3-Clause BSD.
# See LICENSE for details.

OBJFILES=./build/main.o ./build/check_mkdir_error.o ./build/create_c_project.o \
			./build/create_java_project.o ./build/generate_directories.o ./build/generate_files.o \
			./build/create_python_project.o ./build/help_info.o ./build/version_info.o
CFLAGS=-c -Wall -Wswitch-default -Wconversion

default: $(OBJFILES)
	gcc -Wall $(OBJFILES) -o ./build/a.exe

./build/main.o: ./src/main.c
	gcc $(CFLAGS) ./src/main.c -o ./build/main.o

./build/help_info.o: ./src/help_info.c
	gcc $(CFLAGS) ./src/help_info.c -o ./build/help_info.o

./build/version_info.o: ./src/version_info.c
	gcc $(CFLAGS) ./src/version_info.c -o ./build/version_info.o

./build/generate_directories.o: ./src/generate_directories.c
	gcc $(CFLAGS) ./src/generate_directories.c -o ./build/generate_directories.o

./build/generate_files.o: ./src/generate_files.c
	gcc $(CFLAGS) ./src/generate_files.c -o ./build/generate_files.o

./build/check_mkdir_error.o: ./src/check_mkdir_error.c
	gcc $(CFLAGS) ./src/check_mkdir_error.c -o ./build/check_mkdir_error.o

./build/create_c_project.o: ./src/create_c_project.c
	gcc $(CFLAGS) ./src/create_c_project.c -o ./build/create_c_project.o

./build/create_java_project.o: ./src/create_java_project.c
	gcc $(CFLAGS) ./src/create_java_project.c -o ./build/create_java_project.o

./build/create_python_project.o: ./src/create_python_project.c
	gcc $(CFLAGS) ./src/create_python_project.c -o ./build/create_python_project.o

test-c: ./build/a.exe
	./build/a.exe c ./tests/my_pro

test-java: ./build/a.exe
	./build/a.exe java ./tests/my_java_pro

test-python: ./build/a.exe
	./build/a.exe python ./tests/my_python_pro

debug: $(OBJFILES)
	gcc -g ./src/*.c -o ./build/a.exe
	gdb --args ./build/a.exe c my_pro

clean:
	./build/*.o ./build/a.exe
