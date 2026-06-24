#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#include "../include/proinitutil.h"

#define SIZE 200
#define DIR_NAME_ARR_SIZE 3
#define FILE_FUNC_ARR_SIZE 5

static void _create_makefile(FILE*);
static void _create_readme(FILE*);
static void _create_gitignore(FILE*);
static void _create_main(FILE*);
static void _create_manifest(FILE*);

void create_java_project(char* project_name) {
	const char* directory_names[] = {"src/", "docs/", "classes/"};
	const char* file_names[] = {"src/Main.java", "makefile", "README.md", ".gitignore", "manifest.txt"};
	const void (*func_ptr[])(FILE*) = { &_create_main, &_create_makefile, &_create_readme, &_create_gitignore, &_create_manifest };
	char file_path[SIZE];

	strcpy(file_path, project_name);
	strcat(file_path, "/");

	if (0 != mkdir(file_path)) {
		printf("Unable to create project directory\n");
		check_mkdir_error(file_path);
		exit(EXIT_FAILURE);
	}

	create_directories(file_path, directory_names, DIR_NAME_ARR_SIZE);

	create_files(file_path, file_names, func_ptr, FILE_FUNC_ARR_SIZE);
}

static void _create_makefile(FILE* file_ptr) {
	fprintf(file_ptr,	"CLASSPATH=classes/\n"
						"SRCPATH=./src/\n\n"
						"default: $(SRCPATH)Main.java\n"
						"\tjavac $(SRCPATH)Main.java -d ./$(CLASSPATH)\n\n"
						"$(CLASSPATH)Main.class: $(SRCPATH)Main.java\n"
						"\tjavac $(SRCPATH)Main.java -d ./$(CLASSPATH)\n\n"
						"run: $(CLASSPATH)Main.class\n"
						"\tjava -cp $(CLASSPATH) Main\n\n"
						"jar:\n"
						"\tjar -cvmf manifest.txt Main.jar -C classes .");

}

static void _create_readme(FILE* file_ptr) {
	fprintf(file_ptr,	"# README\n\n"
						"Information about this program.");
}

static void _create_gitignore(FILE* file_ptr) {
	fprintf(file_ptr,	"*.swp\n"
						"*~\n"
						"*.class\n"
						"build/\n"
						"*.jar\n");
}

static void _create_main(FILE* file_ptr) {
	fprintf(file_ptr,	"public class Main {\n"
						"\tpublic static void main(String[] args) {\n"
						"\t\tSystem.out.println(\"Hello, world!\");\n\t}\n}"
	);
}

static void _create_manifest(FILE*file_ptr) {
	fprintf(file_ptr,	"Manifest-Version: 1.0\n"
						"Main-Class: Main\n");
}
