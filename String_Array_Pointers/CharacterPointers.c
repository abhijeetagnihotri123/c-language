#include <stdio.h>

int main(){

    char var1;

    printf("Number of bytes for character variable is [ %ld ]\n" , sizeof(var1));

    char *var2;

    
    printf("Number of bytes for character pointer variable is [ %ld ]\n" , sizeof(var2));

    var2 = "Hi";

    printf("Number of bytes for character pointer variable is [ %ld ]\n" , sizeof("Hi"));

    return 0;

}