#include <stdio.h>

int main(void)
{
    float height,width,perimeter;
    printf("Enter the height of the rectangle : ");
    scanf("%f",&height);
    printf("Enter the width of the rectangle : ");
    scanf("%f",&width);

    perimeter = 2 *(width+height);

    printf("perimeter of rectangle : %.2f\n",perimeter);

    return 0;

}