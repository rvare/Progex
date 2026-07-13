/*
Copyright (c) 2026 Richard Varela.
This file is part of Progex which is release under 3-Clause BSD.
See LICENSE for details.
*/

#include <stdio.h>

void help_info() {
	printf(	"Usage: progex [OPTION] [LANGUAGE] [PROJECT NAME]\n");
	printf(	"Supported langauges:\n"
			"\tC\n"
			"\tJava\n"
			"\tPython\n\n");
	printf(	"The PROJECT NAME parameter must be a valid directory path.\n"
			"Typically, you can just give the project's name and the program\n"
			"will create the project directories and files in the current directory.\n\n");
}
