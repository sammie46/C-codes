#include <stdio.h>
#include <stdlib.h>

int main()
{
  
 float N, W, L, M, O;


    printf("Enter N: ");
    scanf("%f", &N);

    printf("Enter W: ");
    scanf("%f", &W);

    printf("Enter L: ");
    scanf("%f", &L);

    printf("Enter M: ");
    scanf("%f", &M);

    printf("Enter O: ");
    scanf("%f", &O);

    float area_playground = N * N;
    float area_bench = M * O;
    float area_tile = W * L;
    float area_to_cover = area_playground - area_bench;
    float tiles_needed = area_to_cover / area_tile;
    float time_needed = tiles_needed * 0.2;

    printf("Needed tails: %.2f\n", tiles_needed);
    printf("Needed time: %.2f min\n", time_needed);


    return 0;
}
