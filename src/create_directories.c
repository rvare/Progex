#include <string.h>
#include <sys/stat.h>
#include <error.h>
#include <stdio.h>

#include "../include/proinitutil.h"

#define SIZE 200

void create_directories(char* file_path, const char* directory_names[], const int size) {
	size_t proname_len = strlen(file_path);
	for (int i = 0; i < size; ++i) {
		strcat(file_path, directory_names[i]);
		int success = mkdir(file_path);
		if (success == 0)
			printf("Subdirectory created: %s\n", file_path);
		else {
			printf("ERROR: Unable to create subdirectory: %s\n", file_path);
			check_mkdir_error(file_path);
		}
		memset(file_path+proname_len, ' ', SIZE-proname_len);
		file_path[proname_len] = '\0';
	}
}
