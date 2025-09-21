#include <stdio.h>
#include <stdlib.h>

int main()
{
  
    char symbol;
    scanf("%c",&symbol);
    int redove;
    scanf("%d",&redove);
    
  for (int i = 1; i<=redove; i++)
    {
        for (int j=1;j<=redove - i;j++)
            {
                printf(" ");
            }
        for (int j = 1; j<=(2*i -1); j++)
        {
            if (j== 1 || j == (2*i-1) || i==redove)
            {
                printf("%c",symbol);
            }
            else
                {
                    printf(" ");
                }
        }
        printf("\n");
    }


   for (int i = redove; i>=1; i--)
    {
        for (int j=1;j<=redove - i;j++)
            {
                printf(" ");
            }
        for (int j = 1; j<=(2*i -1); j++)
        {
            if (j== 1 || j == (2*i-1) || i==redove)
            {
                printf("%c",symbol);
            }
            else
                {
                    printf(" ");
                }
        }
        printf("\n");
    }

    return 0;
}
