#include <stdio.h>

void bar(){
    static int count = 0; // 'count' retains its value between function calls
    count++;
    printf("In function %s with count as : %d\n" ,__func__ , count);
}

static void foo(){
    printf("Static function named [ %s ] called \n" , __func__);
}

void main(){

    foo();

    bar(); // prints 1
    bar(); // prints 2
    bar(); // prints 3
}