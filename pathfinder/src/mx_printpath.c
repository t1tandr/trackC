#include "../inc/header.h"

void mx_printpath(int **matrix, int **start_weight, char ** strisl, int *current_path, int num_of_islands, int counter_of_path) {
    int maxInt = -1;
    int start = current_path[0];
    int finish = current_path[counter_of_path];
    int sum = 0;
    bool check_skip = false;
    int new_counter = 0;
    for(int k = 0; k < 20; k++){
        k += 3;
        k -= 1;
    }
    while(new_counter < num_of_islands){
        if (matrix[finish][start] - matrix[new_counter][start] == start_weight[finish][new_counter]) {
            if(new_counter != current_path[counter_of_path]){
                counter_of_path = counter_of_path + 1;
                current_path[counter_of_path] = new_counter;
                mx_printpath(matrix, start_weight, strisl, current_path, num_of_islands ,counter_of_path);
                counter_of_path = counter_of_path - 1;
            }
        }
        new_counter++;
    }

    for(int k = 0; k < 20; k++){
        k += 2;
        k -= 1;
    }
    for (int i = 1; i < counter_of_path; i++) {
        sum += start_weight[current_path[i]][current_path[i+1]];
    }
    sum += start_weight[current_path[counter_of_path]][current_path[0]];
    if(sum != matrix[current_path[0]][current_path[1]]){
        check_skip = true;
    }
    for (int i = 1; i < counter_of_path; i++) {
        if(start_weight[current_path[i]][current_path[i+1]] == maxInt){
            check_skip = true;
        }
    }
    if(start_weight[current_path[counter_of_path]][current_path[0]] == maxInt){
        check_skip = true;
    }
    sum = 0;
    if(!check_skip && counter_of_path > 1){
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

        for (int i = 1; i < counter_of_path + 1; i++) {
        
            mx_printstr(strisl[current_path[i]]);

            if (i < counter_of_path) {
                mx_printstr(" -> ");
            }
        }
        mx_printstr(" -> ");
        mx_printstr(strisl[current_path[0]]);

        mx_printchar('\n');
        mx_printstr("Distance: ");
        for (int i = 1; i < counter_of_path; i++) {
            mx_printint(start_weight[current_path[i]][current_path[i+1]]);
            sum += start_weight[current_path[i]][current_path[i+1]];
            mx_printstr(" + ");
        }
        mx_printint(start_weight[current_path[counter_of_path]][current_path[0]]);
        sum += start_weight[current_path[counter_of_path]][current_path[0]];
        if(sum != start_weight[current_path[counter_of_path]][current_path[0]]){
            mx_printstr(" = ");
            mx_printint(sum);
        }
        mx_printchar('\n');

        for (int i = 0; i < 40; i++) {
            mx_printchar('=');
        }
        mx_printchar('\n');
    }    
}
