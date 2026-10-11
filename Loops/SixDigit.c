#include <stdio.h>
#include <stdbool.h>

int main() {
    long int num;
    printf("Enter a six-digit number: ");
    scanf("%ld", &num);

    int sum = 0;
    int prod = 1;
    bool hasOdd = false; 

    while (num != 0) {
        int rem = num % 10;
        
        if (rem % 2 == 0) {
            sum += rem;
        } else {
            prod *= rem;
            hasOdd = true; 
        }
        
        num /= 10;
    }

    printf("Sum of even digits: %d\n", sum);
    printf("Product of odd digits: %d\n", hasOdd ? prod : 0);

    return 0;
}