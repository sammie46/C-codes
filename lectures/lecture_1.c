#include <stdio.h>
#include <stdlib.h>
/*#define START 0
#define END 20
#define STEP 1*/

/*int inputCel()
{
    int cel;
    printf("Cel:");
    scanf("%d",&cel);
    return cel;

}*/

int input(char prompt[])
{
    int result;
    printf(prompt);
    scanf("%d",&result);
    return result;
}
void output(int cel, float far)
{
    //printf("%d C->%.2f F\n",cel,far);
    printf("%d\t\t%g\n",cel,far);
}

int main()
{
   /* Kod s constanta const int start=0,;
   const int end=20;
   const int step=1;*/
    //float far;

    int start,end,step;
    int cel;

    start = input("START=");
    end=input("END=");
    do{
            step=input("STEP=");
    } while (step<=0);


    //printf("Hello world!\n");

    printf("Cel\t\tFAR\n");
    printf("---------------------\n");

    //for (cel=START;cel<=END;cel+=STEP)

     for (cel=start;cel<=end;cel+=step)
    {

        output(cel,cel*9./5+32);
    }
    /*cel=inputCel();
    far=cel*9./5+32;
    output(cel,far);*/
    return 0;
}
