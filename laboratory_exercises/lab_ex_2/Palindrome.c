#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int pol = 0; 

    int original_n = n; 

    while (n > 0) {
        int ostatuk = n % 10;  
        n /= 10;              
        pol = pol * 10 + ostatuk; 
    }

    if (original_n == pol) {
        printf("The number is a palindrome.");
    } else {
        printf("The number is not a palindrome.");
    }

    return 0;
}
