#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    if (n%2==0)
    {
        printf("The number is even!\n ");

    }
    else
    {
            printf("The number is odd!\n");
    }

    if (n % 3 == 0 && n % 5 == 0)
            {
            printf("the number is a multiple of 3 and 5\n");
        }
    else
        {
        printf("the number is нот a multiple of 3 and 5\n");
        }

        if ( n > 0){
            printf("The number is positive\n");
        }
        else if (n < 0){
            printf("The number is negative\n");
        }
        else{printf("The number is 0\n");}

    return 0;
}
