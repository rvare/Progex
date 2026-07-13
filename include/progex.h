/*
Copyright (c) 2026 Richard Varela.
This file is part of Progex which is release under 3-Clause BSD.
See LICENSE for details.
*/

#define DIR_PATH_SIZE	100 // Used for strings that represent directory paths.

void create_c_project(char* project_name);
void create_java_project(char* project_name);
void create_python_project(char* project_name);
void help_info();
void version_info();

// Helper functions
void generate_directories(char* file_path, const char* directory_names[], const size_t size);
void generate_files(char* file_path, const char* file_names[], const void (*func_ptr[])(FILE*), const size_t size);

void check_mkdir_error(char* dir_path);
