#ifndef HEADER_H
#define HEADER_H

#ifdef __MACH__
#include <malloc/malloc.h> 
#else 
 
#include <malloc.h> 
 
#define malloc_size malloc_usable_size 
#endif

#include "../libmx/inc/libmx.h"

void mx_check_str(char *str, int *res_line, bool *check_error);
char *mx_check_file(const char *file);
void mx_line_error(int c);
char** mx_str_to_arr(char* str, int lines, int *numIslands, bool* errorCheck);
char** mx_makeislandsarr(char** source, int lines, int numIslands);
void mx_printpath(int **weight, int **start_weight, char ** strisl, int *current_path, int num_of_islands, int counter_of_path);
void mx_floyd(char **strarr, int lines, int num_of_islands, char ** strisl);

#endif
