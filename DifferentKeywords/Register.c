#include <stdio.h>

void main(){

    register int a = 10; // register storage class suggests that the variable should be stored in a CPU register for faster access, but it's just a hint and may be ignored by the compiler

    printf("%d\n" , a);

}