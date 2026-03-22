#include <stdio.h>

int calculateResult(int input1 , int input2 , int operation){

    int answer;

    switch (operation)
    {
    case 0:
        answer = input1 + input2;
        break;
    
    case 1:
        answer = input1 - input2;
        break;
    
    case 2:
        answer = input1 * input2;
        break;
    
    case 3:
        answer = (input2 == 0)?(__INT_MAX__) : (input1/input2);
        break;    
    default:
        answer = __INT_MAX__;
        break;
    }

    return answer;
}

void runCalculatorApplication(){

    int input1,input2, answer , opt;

    printf("Welcome to calculator application\n");

    int ch = 0;

    while(ch == 0)
    {   
        printf("Enter first number\n");   
        scanf("%d" , &input1);
        printf("Enter second number\n");
        scanf("%d" , &input2);

        printf("Enter 0 for addition\nEnter 1 for subtraction\nEnter 2 for multiplication\nEnter 3 for division\n");
        scanf("%d" , &opt);
        
        answer = calculateResult(input1 , input2 , opt);
        
        if(answer == __INT_MAX__)
        {
            printf("Either the operation you entered is illegal or some error occured\n");
        }
        else
        {
            printf("Answer is %d\n" , answer);
        }

        printf("Want to do more operations press 0 or press any other key to exit\n");
        scanf("%d", &ch); 
    }

}


int calculateResult1(int input1 , int input2 , char operation){

    int answer;

    switch (operation)
    {
    case '+':
        answer = input1 + input2;
        break;
    
    case '-':
        answer = input1 - input2;
        break;
    
    case '*':
        answer = input1 * input2;
        break;
    
    case '/':
        answer = (input2 == 0)?(__INT_MAX__) : (input1/input2);
        break;    
    default:
        answer = __INT_MAX__;
        break;
    }

    return answer;
}

void runCalculatorApplication1(){

    int input1,input2, answer;

    printf("Welcome to calculator application\n");

    char ch = 'y';

    char opt;

    while(ch == 'y')
    {   
        printf("Enter first number\n");   
        scanf("%d" , &input1);
        printf("Enter second number\n");
        scanf("%d" , &input2);
        printf("Enter + for addition\nEnter - for subtraction\nEnter * for multiplication\nEnter / for division\n");
        scanf("\n%c" , &opt);
        
        answer = calculateResult1(input1 , input2 , opt);
        
        if(answer == __INT_MAX__)
        {
            printf("Either the operation you entered is illegal or some error occured\n");
        }
        else
        {
            printf("Answer is %d\n" , answer);
        }

        printf("Want to do more operations press 0 or press any other key to exit\n");
        scanf("\n%c", &ch); 
    }

}

void main(){

    runCalculatorApplication1();

}