#include <stdio.h>

extern int a; // global variable 'a' is declared here

extern void fooOther();

void foo(){

    a = a + 1;
    printf("In function %s with value of a as : %d\n" ,__func__ ,  a); // prints 11

}

void main(){

    foo();
    fooOther(); // this function is defined in SomeOtherFile.c and also modifies the global variable 'a'
    a = a + 1;

    printf("In function %s with value of a as : %d\n" ,__func__ , a);

}