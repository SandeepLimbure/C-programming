#include <stdio.h>

int main(){
    int a = 12;
    printf("Initial value of a : %d\n", a);
    // prefix Increment - value is incremented first and then used in expression
    printf("Prefix Increment : %d\n", ++a); // a becomes 13, then used
    // postfix Increment - value is used first and then incremented in expression
    printf("Postfix Increment : %d\n", a++); // a used as 13, then becomes 14
    printf("Value of a after Postfix Increment : %d\n", a); // a is now 14  
    // prefix Decrement - value is decremented first and then used in expression
    printf("Prefix Decrement : %d\n", --a); // a becomes 13, then used
    // postfix Decrement - value is used first and then decremented in expression       
    printf("Postfix Decrement : %d\n", a--); // a used as 13, then becomes 12
    printf("Value of a after Postfix Decrement : %d\n", a); // a is now 12
    return 0;
}