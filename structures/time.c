#include <stdio.h>

struct Time{
    short int hour;
    short int minute;
    short int seconds;
};

int main(void)
{
    struct Time t1,t2;

    printf("Enter the Hour : ");
    scanf("%hd",&t1.hour);

    printf("Enter the minute : ");
    scanf("%hd",&t1.minute);

    printf("Enter the seconds : ");
    scanf("%hd",&t1.seconds);

    printf("Enter the Hour : ");
    scanf("%hd",&t2.hour);

    printf("Enter the minute : ");
    scanf("%hd",&t2.minute);

    printf("Enter the seconds : ");
    scanf("%hd",&t2.seconds);

    printf("%hd : %hd : %hd\n",t1.hour,t1.minute,t1.seconds);

    printf("%hd : %hd : %hd\n",t2.hour,t2.minute,t2.seconds);

    return 0;

}