void create_c_project(char* project_name);
void create_java_project(char* project_name);

void create_directories(char* file_path, const char* directory_names[], int size);
void create_files(char* file_path, const char* file_names[], const void (*func_ptr[])(FILE*), int size);

void check_mkdir_error(char* dir_path);
