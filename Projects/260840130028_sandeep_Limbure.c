




#include <stdio.h>
#include <string.h>

// #define YEAR           1
// #define HEX         2
// #define FIBONACCI   3
// #define LCMHCF      4
// #define PASCAL      5

/*
   Q41. Write a program to find whether a year is leap or not.
*/
int isleap(int year)
{
    if((year%4==0 && year%100!=0) || (year%400 == 0))
    {
        return 1;
    }
    return 0;
}


/*
    Q42. Write a program to convert Hexadecimal into Decimal.
*/
long Hex_to_Dec(char Hex[])
{
    long decimal = 0;
    int base = 1;
    int len = strlen(Hex);

    for(int i = len-1 ; i >= 0; i--)
    {
        if(Hex[i] >= '0' && Hex[i] <= '9')
        {
            decimal += (Hex[i] - '0')*base;
        }
        if(Hex[i] >= 'A' && Hex[i] <= 'F')
        {
            decimal += (Hex[i] - 'A' + 10)*base;
        }

        base *= 16;
    }

    return decimal;

}


/*
   Q43. Write a program to generate a fibonacci series 1,1,2,3,5,8,11,34,55,89.
*/
int fibonacci(int n)
{
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(n == 1) return 1;

    int prev = 0, curr = 1, next;
    for(int i = 2; i <= n; i++)
    {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}   


/*
   Q44. Write a C program to find LCM and HCF of two numbers. 
*/
int HCF(int a, int b)
{
    if(a == 0)
    {
        return b;
    }
    return HCF(b%a , a);
}

int LCM(int a, int b, int gcd)
{
    if(gcd == 0)
    {
        return 0;
    }
    return ((a*b)/gcd);
}


/*
   Q45. Write a program to print pascals triangle.

                    1
                  1   1
                1   2   1
              1   3   3   1
            1   4   6   4   1
*/
int fact(int n)
{
    int fact = 1;
    for(int i = 1;i<=n;i++)
    {
        fact *= i;
    }
    return fact;
}

void pascal_traingle(int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n-i;j++)
        {
            printf(" ");
        }
        for(int k = 0;k <= i;k++)
        {
            int num = fact(i) / (fact(k)*fact(i-k));
            printf("%d  ",num);
        }
        printf("\n");
    }
}



int main(void)
{

    #if YEAR
        int year;
        printf("Enter the year :");
        scanf("%d",&year);

        int leap = isleap(year);
        if(leap == 1)
        {
           printf("%d is a leap year.\n",year);
        }
        else
        {
           printf("%d is not a leap year.\n",year);
        }
    #endif

    #if HEX
        char str[30];

        printf("Enter a Hex value : ");
        fgets(str,sizeof(str),stdin);

        long decimal = Hex_to_Dec(str);
        printf("The decimal number is : %ld",decimal);
    #endif

    #if FIBONACCI
        
        int num;

        printf("Enter the number : ");
        scanf("%d",&num);

        printf("The Fibonacci series : \n");
        for(int i = 1;i <= num; i++)
        {
            printf("%d ",fibonacci(i));
        }
    
        #endif

    #if LCMHCF

        int num1,num2;

        printf("Enter num1 and num2 : ");
        scanf("%d %d",&num1,&num2);

        int gcd = HCF(num1,num2);

        int lcm = LCM(num1,num2,gcd);

        printf("The HCF of %d and %d is %d.\n",num1,num2,gcd);

        printf("The LCM of %d and %d is %d.\n",num1,num2,lcm);

    #endif

    #if PASCAL
       
        int n;

        printf("Enter a number : ");
        scanf("%d",&n);

        pascal_traingle(n);

    #endif

    return 0;
}