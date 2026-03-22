#include <stdio.h>

int main(){

    short a_short[5] = {10 , 20 , 30 , 40 , 50};
    int a_int[5] = {11 , 21 , 31 , 41 , 51};

    printf("sizeof(a_short) : [ %ld ]\n" , sizeof(a_short));
    printf("sizeof(a_int) : [ %ld ]\n" , sizeof(a_int));


    return 0;
}