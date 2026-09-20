/*
Copyright (c) 2026 Richard Varela.
This file is part of Progex which is release under 3-Clause BSD.
See LICENSE for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/progex.h"

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		fprintf(stderr,	"No arguments given!\n"
						"Provide a language and project name to get started.");
		printf("%s\n", argv[0]);
		return 1;
	}

	// Convert the first argument to lower case.
	for (size_t i = 0; argv[1][i]; ++i) {
		argv[1][i] = (char)tolower((int)argv[1][i]);
	}

	if (strcmp(argv[1], "--help") == 0) {
		help_info();
	}
	else if (strcmp(argv[1], "--version") == 0) {
		version_info();
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
		fprintf(stderr, "The language given is either not supported, is spelled wrong, or does not exits.\n");
		fprintf(stderr, "The following are supported languages: C, Java, Python.");
		return 1;
	}

	return 0;
}
