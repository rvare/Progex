#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

#include "../include/proinitutil.h"

void generate_files(char* file_path, const char* file_names[], const void (*func_ptr[])(FILE*), const size_t size) {
	size_t proname_len = strlen(file_path);
	for (size_t i = 0; i < size; ++i) {
		strcat(file_path, file_names[i]);
		FILE *file_ptr = fopen(file_path, "w");
		if (file_ptr == NULL) {
			char err_msg[DIR_PATH_SIZE+50];
			sprintf(err_msg, "Could not create file: %s", file_path);
			perror(err_msg);
		}
		else {
			func_ptr[i](file_ptr);
			fclose(file_ptr);
			printf("Created file: %s\n", file_path);
		}
		memset(file_path+proname_len, ' ', DIR_PATH_SIZE-proname_len);
		file_path[proname_len] = '\0';
	}
}
