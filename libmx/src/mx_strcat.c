#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2){
    int size1 = mx_strlen(s1);
    int size2 = mx_strlen(s2);
    int i = size1;
    for(int j = 0; i < size1 + size2; j++) {
        s1[i] = s2[j];
        i++;
    }
    s1[i++] = '\0';
    return s1;
}

