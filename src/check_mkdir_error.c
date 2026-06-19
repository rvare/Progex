#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "../include/proinitutil.h"

void check_mkdir_error(char* dir_path) {
	switch (errno) {
		case EEXIST:
			printf("Directory %s already exists.\n", dir_path);
			break;
		case EACCES:
			printf("Parent directory does not have write permission.\n"
					"Either change permission of the current directory or find a new directory for project.\n");
			break;
		case ENOSPC:
			printf("Cannot create direcotry because user's does not have enough disk space.\n");
			break;
		case ENAMETOOLONG:
			printf("Directory path name is too long.\n");
			printf("\t%s\n", dir_path);
			break;
		default:
			printf("An error occured. Value of errno: %d\n", errno);
			break;
	}
}
