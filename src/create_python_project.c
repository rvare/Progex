#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#include "../include/proinitutil.h"

#define SIZE 200
#define DIR_NAME_ARR_SIZE 3
#define FILE_FUNC_ARR_SIZE 4

// These functions should stay private in this file.
static void _create_makefile(FILE*);
static void _create_readme(FILE*);
static void _create_gitignore(FILE*);
static void _create_main(FILE*);

void create_python_project(char* project_name) {
	const char* directory_names[] = {"src/", "docs/", "tests/"};
	const char* file_names[] = {"./src/main.py", "README.md", "makefile", ".gitignore"};
	const void (*func_ptr[])(FILE*) = { &_create_main, &_create_readme, &_create_makefile, &_create_gitignore };
	char file_path[SIZE];

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


static void _create_makefile(FILE* file_ptr) {
	fprintf(file_ptr,	"default: main.py\n"
						"\tpython main.py\n");
}

static void _create_readme(FILE* file_ptr) {
	fprintf(file_ptr,	"# README\n\n"
						"Information about this program.");
}

static void _create_gitignore(FILE* file_ptr) {
	fprintf(file_ptr,	"*.swp\n"
						"*~\n"
						"__pycache__/\n");
}

static void _create_main(FILE* file_ptr) {
	fprintf(file_ptr,	"if __name__ == '__main__':\n"
						"    print('Hello, world!')\n");
}

