#include "../inc/header.h"

char** mx_makeislandsarr(char** source, int lines, int numIslands) {
    char** result = (char **)malloc((numIslands + 1) * sizeof(char *));
    int numCells = lines * 3;
    int islandCounter = 0;

    for (int i = 0; i < numCells; i++) {
        if (i % 3 == 2) {
            continue;
        }

        bool check = false;
        for (int j = 0; j < islandCounter; j++) {
            if (result[j] && mx_strcmp(result[j], source[i]) == 0) {
                check = true;
                break;
            }
        }

        if (!check) {
            result[islandCounter] = mx_strdup(source[i]);
            islandCounter++;
        }
    }
    result[islandCounter] = NULL;
    return result;
}
