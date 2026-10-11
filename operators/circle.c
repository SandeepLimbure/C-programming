#include <stdio.h>

#define PI 3.14

int main(){
    float radius;
    printf("enter the radius of circle : ");
    scanf("%g",&radius);
    float area = PI*radius*radius;
    printf("Area of ciclr : %.3f\n",area);
    float perimeter = 2*PI*radius;
    printf("Perimeter of the circle : %.3f\n",perimeter);
    return 0; 
}