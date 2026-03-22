#include <stdio.h>

int main(){

    char a = 'Z';

    char *ptr;

    int *in_ptr = 0x7ffea117f7cf;

    ptr = &a;

    printf("%p %p\n" , ptr , &a);

    *ptr = 'A';
    a = 'G';

    printf("%c %c\n" , *ptr , a);

    printf("%p\n" , in_ptr);

    // *in_ptr = 8;

    char arr[4];
    in_ptr = arr;

    *in_ptr = 0x65666768;

    int i = 0;
    while(i < 4){
        printf("%c\n" , arr[i]);
        i++;
    }

    return 0;
}