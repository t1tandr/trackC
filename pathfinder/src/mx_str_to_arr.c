#include "../inc/header.h"

char** mx_str_to_arr(char* str, int lines, int *numIslands, bool* errorCheck){
    int arrCounter = 0, i = 0, islandsCounter = 0, bufCounter = 0;
    char **arr = (char **)malloc((lines * 3 + 1)* sizeof(char *));
    char buf[100] = "";
    while(str[i] != '\n'){
            i++;
        }
        i++;
    for(int j = 0; j < lines; j++){
        bufCounter = 0;
        while(str[i] != '-'){
            buf[bufCounter] = str[i];
            bufCounter++;
            i++;
        }
        buf[bufCounter] = '\0';
        arr[arrCounter] = mx_strdup(buf);
        arrCounter++;
        i++;
        bufCounter = 0;
        while(str[i] != ','){
            buf[bufCounter] = str[i];
            bufCounter++;
            i++;
        }
        buf[bufCounter] = '\0';
        arr[arrCounter] = mx_strdup(buf);
        arrCounter++;
        i++;
        bufCounter = 0;
        while(str[i] != '\n'){
            buf[bufCounter] = str[i];
            bufCounter++;
            i++;
        }
        buf[bufCounter] = '\0';
        arr[arrCounter] = mx_strdup(buf);
        arrCounter++;
        i++;
    }
    for(int i = 0; i < arrCounter; i++) {
        if(i % 3 == 2) {
            continue;
        }
        for(int j = 0; j < arrCounter; j++) {
            if(j % 3 == 2) {
                continue;
            }
            if( mx_strcmp(arr[i], arr[j]) == 0 && j > i) {
                break;
            }
            else{
                if(j == arrCounter - 2){
                    islandsCounter++;
                }
            }
        }
    }
    for(int i = 0; i < arrCounter - 1; i++){
        if(i % 3 == 2){
            continue;
        }
        if(mx_strcmp(arr[i], arr[i+1]) == 0){
            mx_line_error(i/3+2);
            mx_del_strarr(&arr);
            *errorCheck = true;
            return NULL;
        }
    }
    for(int i = 0; i < arrCounter; i++) {
        if(i % 3 != 0) {
            continue;
        }
        for(int j = i + 3; j < arrCounter; j++) {
            if(j % 3 == 2) 
                continue;
            if(mx_strcmp(arr[i], arr[j]) == 0) {
                if(j % 3 == 0) {
                    if(mx_strcmp(arr[i + 1], arr[j + 1]) == 0){ 
                        mx_printerr("error: duplicate bridges\n");
                        mx_del_strarr(&arr);
                        *errorCheck = true;
                        return NULL;
                    }
                }
                if(j % 3 == 1) {
                    if(mx_strcmp(arr[i + 1], arr[j - 1]) == 0){ 
                        mx_printerr("error: duplicate bridges\n");
                        mx_del_strarr(&arr);
                        *errorCheck = true;
                        return NULL;
                    }
                }
            }
        }
    } 
    if(islandsCounter != mx_atoi(str)){
        mx_printerr("error: invalid number of islands\n");
        mx_del_strarr(&arr);
        *errorCheck = true;
        return NULL;
    }
    long long sum = 0;
    long long max = 2147483647;
    for(int i = 2; i < arrCounter; i+=3){
        if(i % 3 == 2){
            if(mx_atoi(arr[i]) == max){
                mx_printerr("error: sum of bridges lengths is too big\n");
                mx_del_strarr(&arr);
                *errorCheck = true;
                return NULL;
            }
            sum += mx_atoi(arr[i]);
        }
    }
    if(sum > max){
        mx_printerr("error: sum of bridges lengths is too big\n");
        mx_del_strarr(&arr);
        *errorCheck = true;
        return NULL;
    }
    *numIslands = mx_atoi(str);
    return arr;
}
