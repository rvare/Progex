#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../include/proinitutil.h"

#define DIR_NAME_ARR_SIZE 5
#define FILE_FUNC_ARR_SIZE 4

// These functions should stay private in this file.
static void _create_makefile(FILE*);
static void _create_readme(FILE*);
static void _create_gitignore(FILE*);
static void _create_main(FILE*);

void create_c_project(char* project_name) {
	const char* directory_names[] = {"src/", "include/", "tests/", "build/", "docs/"};
	const char* file_names[] = {"makefile", "README.md", ".gitignore", "src/main.c"};
	const void (*func_ptr[])(FILE*) = { &_create_makefile, &_create_readme, &_create_gitignore, &_create_main };
	char file_path[DIR_PATH_SIZE];

	strcpy(file_path, project_name);
	strcat(file_path, "/");

	if (0 != mkdir(file_path)) {
		printf("Unable to create project directory.\n");
		check_mkdir_error(file_path);
		exit(EXIT_FAILURE);
	}

	generate_directories(file_path, directory_names, DIR_NAME_ARR_SIZE);

	generate_files(file_path, file_names, func_ptr, FILE_FUNC_ARR_SIZE);
}

void _create_makefile(FILE* file_ptr) {
	fprintf(file_ptr,	"OBJFILES=./build/main.o\n"
						"CFLAGS=-c -Wall\n\n"
						"default: $(OBJFILES)\n"
						"\tgcc $(OBJFILES) -o ./build/a.exe\n\n"
						"build/main.o: src/main.c\n"
						"\tgcc $(CFLAGS) src/main.c -o build/main.o\n\n");
}

void _create_readme(FILE* file_ptr) {
	fprintf(file_ptr,	"# README\n\n"
						"Information about this program.");
}

void _create_gitignore(FILE* file_ptr) {
	fprintf(file_ptr,	"*.swp\n"
						"*~");
}

void _create_main(FILE* file_ptr) {
	fprintf(file_ptr,	"#include <stdio.h>\n"
						"#include <stdlib.h>\n\n"
						"int main() {\n"
						"\tprintf(\"Hello, world!\\n\");\n\n"
						"\treturn 0;\n}");
}

