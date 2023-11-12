#include "../inc/header.h"

void mx_floyd(char **strarr, int lines, int num_of_islands, char ** strisl) {
    int maxInt = -1;
    int num_of_iter = 0;
    bool check = false;
    int tempI = 0;
    int tempJ = 0;
    int *current_path = (int*)malloc((num_of_islands + 1) * sizeof(int));
    int counter = 0;
    int **matrix = malloc(sizeof(int*) * num_of_islands);
    for (int i = 0; i < num_of_islands; i++){
        matrix[i] = malloc(sizeof(int) * num_of_islands);
    }
    int **start_weight = malloc(sizeof(int*) * num_of_islands);
    for (int i = 0; i < num_of_islands; i++){
        start_weight[i] = malloc(sizeof(int) * num_of_islands);
    }
    int **history = malloc(sizeof(int*) * num_of_islands);
    for (int i = 0; i < num_of_islands; i++){
        history[i] = malloc(sizeof(int) * num_of_islands);
    }
    for(int i = num_of_islands - 1; i > 0; i--){
        num_of_iter+= i;
    }
    for(int i = 0; i < num_of_islands; i++) {
        for(int j = 0; j < num_of_islands; j++){
            history[i][j] = -1;
            matrix[i][j] = maxInt;   
            start_weight[i][j] = maxInt;
        }
    }
    for(int i = 0; i < lines * 3; i++) {
        tempJ = 0;
        check = false;
        if(i % 3 == 2) {
            continue;
        }
        for(int j = 0; j < i; j++) {
            if(mx_strcmp(strarr[j], strarr[i]) == 0) {
                check = true;
                break;
            }
        }
        if(check){
            continue;
        }
        for(int j = 0; j < lines * 3; j++){
            if(j % 3 == 2) {
                continue;
            }
            if(tempI == tempJ) {
                tempJ++;
                continue;
            }
            if(mx_strcmp(strarr[j], strarr[i]) == 0) {
                if(j % 3 == 0) {
                    for(int k = 0; k < num_of_islands; k++) {
                        if(mx_strcmp(strarr[j + 1], strisl[k]) == 0) {
                            tempJ = k;
                        }
                    }
                    matrix[tempI][tempJ] = mx_atoi(strarr[j+2]);
                    matrix[tempJ][tempI] = mx_atoi(strarr[j+2]);
                    start_weight[tempI][tempJ] = mx_atoi(strarr[j+2]);
                    start_weight[tempJ][tempI] = mx_atoi(strarr[j+2]);
                    history[tempJ][tempI] = tempI;
                    history[tempI][tempJ] = tempJ;
                }
                if(j % 3 == 1) {
                    for(int k = 0; k <num_of_islands; k++) {
                        if(mx_strcmp(strarr[j - 1], strisl[k]) == 0) {
                            tempJ = k;
                        }
                    }
                    matrix[tempI][tempJ] = mx_atoi(strarr[j+1]);
                    matrix[tempJ][tempI] =mx_atoi(strarr[j+1]);
                    start_weight[tempI][tempJ] = mx_atoi(strarr[j+1]);
                    start_weight[tempJ][tempI] =mx_atoi(strarr[j+1]);
                    history[tempJ][tempI] = tempI;
                    history[tempI][tempJ] = tempJ;                   
                }
            }
        
        }
        tempI++;        
    } 
    for (int i = 0; i < num_of_islands; i++) {
        for (int j = 0; j < num_of_islands; j++) {

            if(matrix[i][j] != maxInt) {
                for (int k = 0; k < num_of_islands; k++) {
                    if((matrix[i][k] > matrix[i][j] + matrix[j][k]  || matrix[i][k] == maxInt) && matrix[j][k] != -1 &&(i != k)) {
                        matrix[i][k] = matrix[i][j] + matrix[j][k];
                        history[i][k] = history[i][j];
                    }
                }
            }
        }                     
    }
    for (int i = 0; i < num_of_islands; i++) {
        for(int k = 0; k < 25; k++){
            k += 4;
            k -= 1;
        }
        for (int j = 0; j < num_of_islands; j++){
            if(i >= j){
                continue;
            }
            current_path[0] = j;
            counter = 1;
            current_path[1] = i;
            if(start_weight[current_path[1]][current_path[0]] == matrix[current_path[1]][current_path[0]]){
                for (int i = 0; i < 40; i++) {
                    mx_printchar('=');
                }
                mx_printchar('\n');
                mx_printstr("Path: ");
                mx_printstr(strisl[current_path[1]]);
                mx_printstr(" -> ");
                mx_printstr(strisl[current_path[0]]);
                mx_printchar('\n');
                mx_printstr("Route: ");
                mx_printstr(strisl[current_path[1]]);
                mx_printstr(" -> ");
                mx_printstr(strisl[current_path[0]]);
                mx_printchar('\n');
                mx_printstr("Distance: ");
                mx_printint(matrix[current_path[1]][current_path[0]]);
                mx_printchar('\n');
                for (int i = 0; i < 40; i++) {
                    mx_printchar('=');
                }
                mx_printchar('\n');
            }
            mx_printpath(matrix, start_weight, strisl, current_path, num_of_islands, counter);
        }
    }
    free(current_path);
    for (int i = 0; i < num_of_islands; i++){
        free(matrix[i]);        
    }
    free(matrix);
    matrix = NULL;
    for (int i = 0; i < num_of_islands; i++){
        free(history[i]);        
    }
    free(history);
    history = NULL;
    for (int i = 0; i < num_of_islands; i++){
        free(start_weight[i]);        
    }
    free(start_weight);
}

