#include <stdio.h>

int main(void)
{
    int a = 162;
    int b = 934;
    int c = 200;

    int res = (a > b)
    ? ((b > c) ? b : (a > c ? c : a))
    : ((a > c) ? a : (b > c ? c : b));

    printf("%d\n",res);

    return 0;
}