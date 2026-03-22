#include <stdio.h>

struct pixel_t {
    unsigned char r;
    unsigned char g;
    unsigned char b;

    int l;

}__attribute__((packed)); // This attribute tells the compiler to pack the structure without padding

int main(){

    struct pixel_t pixel1; // Declaring a variable of type struct pixel_t

    printf("%ld\n" , sizeof(struct pixel_t)); // Output: 3 (size of the struct in bytes)
    return 0;
}