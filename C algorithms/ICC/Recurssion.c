//This code is a study for recurssion method used for calculate a factorial of any number.

#include <stdio.h>
int factorial(int number){
    if (number == 0){
        return 1;
    }else{
        return number * factorial(number-1);/*The variable a is a digited number by the user and when calling function,
         *if variable a is diferent of zero, it will return the variable a multiplied by the factorial function itself but number-1,
         *staying in a function call loop until it reaches zero.
         */ 
    }
}

int main(){
    int number;
    printf("Insert a number for calculate his factorial: ");
    scanf("%d", &number);
    printf("The factorial of the number %d is: %d\n", number, factorial(number));
    return 0;
}
