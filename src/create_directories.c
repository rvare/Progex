#include <string.h>
#include <sys/stat.h>
#include <error.h>
#include <stdio.h>

#include "../include/proinitutil.h"

#define SIZE 200

void create_directories(char* file_path, const char* directory_names[], const size_t size) {
	size_t proname_len = strlen(file_path);
	for (size_t i = 0; i < size; ++i) {
		strcat(file_path, directory_names[i]);
		if (0 == mkdir(file_path))
			printf("Subdirectory created: %s\n", file_path);
		else {
			printf("ERROR: Unable to create subdirectory: %s\n", file_path);
			check_mkdir_error(file_path);
		}
		memset(file_path+proname_len, ' ', SIZE-proname_len);
		file_path[proname_len] = '\0';
	}
}
