#include "../inc/header.h"

char *mx_check_file(const char *file){
    char *result = mx_file_to_str(file);
    if(!result){
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist\n");
        exit(0);
    }
    if(mx_strcmp("!", result) == 0){
        mx_printerr("error: file");
        mx_printerr(file);
        mx_printerr(" is empty\n");
        exit(0);
    }
    return result;
}
