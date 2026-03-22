#include <stdio.h>

enum weekday_e {
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

int main(){

    printf("%d\n" , SUNDAY); // Output: 0
    printf("%d\n" , MONDAY); // Output: 1
    printf("%d\n" , TUESDAY); // Output: 2
    printf("%d\n" , WEDNESDAY); // Output: 3
    printf("%d\n" , THURSDAY); // Output: 4
    printf("%d\n" , FRIDAY); // Output: 5   
    printf("%d\n" , SATURDAY); // Output: 6
}