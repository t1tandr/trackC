#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size){
    int counter = 0;
    int is_sorted = 0;
    while (!is_sorted)
    {
        is_sorted = 1;
        for (int i = 0; i < size - 1; i++)
        {
            if (mx_strcmp(arr[i], arr[i + 1]) > 0)
            {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                counter++;
                is_sorted = 0;
            }   
        }
    }
    return counter;
}

