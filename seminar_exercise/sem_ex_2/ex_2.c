#include <stdio.h>
#include <stdlib.h>

    int main() {
    int num1, num2, num3;


    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);


    if (num1 == num2 && num2 == num3)
    {
        printf("yes\n");
    }

    else
    {
        printf("no\n");
    }
      
    return 0;
}
