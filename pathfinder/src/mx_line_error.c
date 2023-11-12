#include "../inc/header.h"

void mx_line_error(int c){
    char* str = mx_itoa(c);
    mx_printerr("error: line ");
    mx_printerr(str);
    mx_printerr(" is not valid\n");

    free(str);
}
