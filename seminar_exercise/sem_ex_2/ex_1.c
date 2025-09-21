#include <stdio.h>
#include <stdlib.h>

int findMax(int a, int b)
{
    return (a > b) ? a : b;
}


int findMin(int a, int b)
{
    return (a < b) ? a : b;
}

int main() {
    int number, maxNumber, minNumber;
    int isFirstNumber = 1;

    printf("Enter numbers (0 to end):\n");
    while (1)
        {
        scanf("%d", &number);

        if (number == 0) break;

        if (isFirstNumber)
        {
            maxNumber = minNumber = number;
            isFirstNumber = 0;
        }

        else
        {

            maxNumber = findMax(maxNumber, number);
            minNumber = findMin(minNumber, number);
        }
    }

    if (isFirstNumber)
    {
        printf("No entered numbers.\n");
    }

    else
    {
        printf("The biggest number is: %d\n", maxNumber);
        printf("The smallest number is: %d\n", minNumber);
    }

    return 0;
}
