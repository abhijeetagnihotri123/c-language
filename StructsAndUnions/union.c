#include <stdio.h>

union my_union{
    char a;
    short b;
};

int main(){

    union my_union u1; // Declaring a variable of type union my_union

    printf("%ld\n" , sizeof(union my_union)); // Output: 0 (size of the union in bytes)

    return 0;
}