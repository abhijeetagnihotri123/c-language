#include <stdio.h>

void main(){
    {
        auto int a = 10; // auto is the default storage class for local variables, so it can be omitted
        printf("%d\n" , a); //until what point variable is available
        // local variable 'a' will go on the stack
    }
}