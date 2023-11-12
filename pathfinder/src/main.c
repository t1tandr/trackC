#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if(argc != 2){
        mx_printerr("usage: ./pathfinder [filename]");
        exit(0);
    }
    char* str = mx_check_file(argv[1]);
    int countLines;
    int numIslands;
    bool checkError;
    mx_check_str(str, &countLines, &checkError);
    if(checkError){
        mx_strdel(&str);
        exit(0);
    }
    char** sourceArr = NULL;
    sourceArr = mx_str_to_arr(str, countLines, &numIslands, &checkError);
    if(checkError){
        mx_strdel(&str);
        exit(0);
    }
    char** islandArr = mx_makeislandsarr(sourceArr, countLines, numIslands);
    mx_floyd(sourceArr, countLines, numIslands, islandArr);
    mx_strdel(&str);
    mx_del_strarr(&sourceArr);
    mx_del_strarr(&islandArr);
    return 0;
}
