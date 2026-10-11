#include <stdio.h>

int main(){
    int a;
    printf("Enter a number : - ");
    scanf("%d",&a);
    printf("Octal number of %d is = %o\n",a,a);
    printf("Hexadecimal number of %d is = %x\n",a,a);
    return 0;
}