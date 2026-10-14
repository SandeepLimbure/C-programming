#include <stdio.h>

int isPalindrome(int n)
{
    if (n < 0)
        return 0;

    int original = n;
    int rev = 0;

    while (n != 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    return (rev == original);
}

int main(void)
{
    int arr[] = {111, 222, 333, 444};
    int n = 4;
    int allPalindromes = 1;

    for (int i = 0; i < n; i++)
    {
        if (!isPalindrome(arr[i]))
        {
            allPalindromes = 0;
        }
    }

    if (allPalindromes)
    {
        printf("The array is a palindrome array.\n");
    }
    else
    {
        printf("The array is not a palindrome array.\n");
    }

    return 0;
}