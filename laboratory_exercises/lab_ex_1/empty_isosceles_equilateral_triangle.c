#include <stdio.h>
#include <stdlib.h>

int main()
{
    char symbol;
    scanf("%c", &symbol);

    int height;
    scanf("%d", &height);

    for (int i = 1; i <= height; i++){
        for (int j = 1; j <= height - i; j++){
                printf(" ");
        }

        for (int j = 1; j <= (2*i - 1); j++){
                if (j== 1 || j == (2*i-1) || i==height){
                    printf("%c", symbol);
                }
                else{
                    printf(" ");
                }
        }

         printf("\n");

    }

    return 0;
}
