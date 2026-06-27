#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/proinitutil.h"

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		fprintf(stderr, "Not enough args\n");
		printf("%s\n", argv[0]);
		return 1;
	}

	if (strcmp(argv[1], "--help") == 0) {
		printf("Display help info\n");
	}
	else if (strcmp(argv[1], "--version") == 0) {
		printf("Display version info\n");
	}
	else if (strcmp(argv[1], "c") == 0) {
		printf("Create C project\n");
		printf("%s\n", argv[2]);
		create_c_project(argv[2]);
	}
	else if (strcmp(argv[1], "java") == 0) {
		printf("Create Java project\n");
		printf("%s\n", argv[2]);
		create_java_project(argv[2]);
	}
	else if (strcmp(argv[1], "python") == 0) {
		printf("Create Python project\n");
		printf("%s\n", argv[2]);
		create_python_project(argv[2]);
	}
	else {
		fprintf(stderr, "Display error information\n");
		return 1;
	}

	return 0;
}
