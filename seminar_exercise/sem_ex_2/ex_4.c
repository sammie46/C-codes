#include <stdio.h>
#include <stdlib.h>

    int main() {

    float V, P1, P2, N;

    printf("Enter the volume of the pool: ");
    scanf("%f",&V);

    printf("Enter the flow rate of the first pipe: ");
    scanf("%f",&P1);

    printf("Enter the flow rate of the second pipe: ");
    scanf("%f",&P2);

    printf("Enter the time the pipes are running for: ");
    scanf("%f",&N);


    P1 /= 1000;
    P2 /= 1000;

    float totalWater = (P1 + P2) * N;

    if (totalWater <= V)
    {
        float filledPercent = (totalWater / V) * 100;
        float pipe1Percent = (P1 * N / totalWater) * 100;
        float pipe2Percent = (P2 * N / totalWater) * 100;

        printf("The pool is filled %.2f%%.\n", filledPercent);
        printf("Pipe 1 filled with %.2f%% of the water.\n", pipe1Percent);
        printf("Pipe 2 filled with %.2f%% of the water.\n", pipe2Percent);
    }

    else
    {
        float overflow = totalWater - V;
        printf("The pool is overfloat with %.2f.\n", overflow);
    }

    return 0;
}

