#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#include "../include/proinitutil.h"

#define SIZE 200
#define DIR_NAME_ARR_SIZE 5
#define FILE_FUNC_ARR_SIZE 4

// These functions should stay private in this file.
void _create_makefile(FILE*);
void _create_readme(FILE*);
void _create_gitignore(FILE*);
void _create_main(FILE*);

void create_c_project(char* project_name) {
	const char* directory_names[] = {"src/", "include/", "tests/", "build/", "docs/"};
	const char* file_names[] = {"makefile", "README.md", ".gitignore", "src/main.c"};
	const void (*func_ptr[])(FILE*) = { &_create_makefile, &_create_readme, &_create_gitignore, &_create_main };
	char file_path[SIZE] = "./";
	int success;

	strcat(file_path, project_name);
	strcat(file_path, "/");
	size_t proname_len = strlen(file_path);

	success = mkdir(file_path);
	if (success != 0) {
		printf("Unable to create project directory.\n");
		check_mkdir_error(file_path);
		exit(EXIT_FAILURE);
	}

	// Create directories
	for (int i = 0; i < DIR_NAME_ARR_SIZE; ++i) {
		strcat(file_path, directory_names[i]);
		success = mkdir(file_path);
		if (success == 0)
			printf("Subdirectory created: %s\n", file_path);
		else {
			printf("ERROR: Unable to create subdirectory: %s\n", file_path);
			check_mkdir_error(file_path);
		}
		memset(file_path+proname_len, ' ', SIZE-proname_len);
		file_path[proname_len] = '\0';
	}

	// Create files
	for (int i = 0; i < FILE_FUNC_ARR_SIZE; ++i) {
		strcat(file_path, file_names[i]);
		FILE *file_ptr = fopen(file_path, "w");
		if (file_ptr == NULL) {
			char err_msg[SIZE+100];
			sprintf(err_msg, "Could not create file: %s", file_path);
			perror(err_msg);
		}
		else {
			func_ptr[i](file_ptr);
			fclose(file_ptr);
			printf("Created file: %s\n", file_path);
		}
		memset(file_path+proname_len, ' ', SIZE-proname_len);
		file_path[proname_len] = '\0';
	}
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

