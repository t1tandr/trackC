#include "../inc/header.h"

void mx_check_str(char *str, int *count_lines, bool *errorCheck){
    int i = 0;
    while(str[i] != '\n'){
        if(!mx_isdigit(str[i])){
            mx_line_error(1);
            *errorCheck = true;
            return;
        }
        if(i > 11){
            mx_line_error(1);
            *errorCheck = true;
            return;
        }
        i++;
    }
    if(mx_atoi(str) >= 2147483647){
        mx_line_error(1);
        *errorCheck = true;
        return;
    }
    int line = -1;
    int minusCount = 0;
    int komaCount = 0;
    i = 0;
    while(str[i] != '\0'){
        if(str[i] == '\n'){
            line++;
        }
        if(line >= 0){
            if(str[i] == ','){
                komaCount++;
            }
            if(str[i] == '-'){
                minusCount++;
            }
            if(str[i] == '\n' && line > 0){
                if(komaCount != 1 || minusCount != 1){
                    mx_line_error(line + 1);
                    *errorCheck = true;
                    return;
                }
                komaCount = 0;
                minusCount = 0;
            }
        }
        if(str[i+1] == '\0' && str[i] != '\n'){
            mx_line_error(line + 1);
            *errorCheck = true;
            return;
        }
        i++;
    }
    i = 0;
    while(str[i] != '\n'){
        i++;
    }
    i++;
    for (int j = 0; j < line; j++){
        if(str[i] == '-'){
            mx_line_error(j+2);
            *errorCheck = true;
            return;
        }
        while(str[i] != '-'){
            if(!mx_isalpha(str[i])){
                mx_line_error(j+2);
                *errorCheck = true;
                return;
            }
            i++;
        }
        if(str[i] == '-'){
            i++;
        }
        if(str[i] == ','){
            mx_line_error(j+2);
            *errorCheck = true;
            return;
        }
        while(str[i] != ','){
            if(!mx_isalpha(str[i])){
                mx_line_error(j+2);
                *errorCheck = true;
                return;
            }
            i++;
        }
        if(str[i] == ','){
            i++;
        }
        if(str[i] == '\n'){
            mx_line_error(j+2);
            *errorCheck = true;
            return;
        }
        while(str[i] != '\n'){
            if(!mx_isdigit(str[i])){
                mx_line_error(j+2);
                *errorCheck = true;
                return;
            }
            i++;
        }
        if(str[i] == '\n'){
            i++;
        }
    }
    *count_lines = line;
}
