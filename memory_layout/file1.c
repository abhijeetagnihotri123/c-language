int x = 1;
static int y = 2;
static int z = 3;

#include <stdio.h>

extern int x;

int main(){

    printf("%d %d\n" , x , x);

    return 0;
}