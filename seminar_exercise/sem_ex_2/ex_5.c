#include <stdio.h>
#include <stdlib.h>

    int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int width = 2 * n - 1;
    int height = 2 * (n - 2) + 1;
    int middle = height / 2;


    for (int i = 0; i < n - 1; i++) {
        
      for (int j = 0; j < n - 1; j++) {
            if (i % 2 == 0) printf("*");
            
            else printf("-");
        }
        
      printf("\\ /");
        
      for (int j = 0; j < n - 1; j++) {
            if (i % 2 == 0) printf("*");
            else printf("-");
        }
        
      printf("\n\n");
    }

    
      for (int j = 0; j < n - 1; j++) printf(" ");
    printf(" @ ");
    
      for (int j = 0; j < n - 1; j++) printf(" ");
    printf("\n");


    for (int i = n - 2; i >= 0; i--) {
        
      for (int j = 0; j < n - 1; j++) {
            if (i % 2 == 0) printf("*");
            else printf("-");
        }
        
    printf("/ \\");
        
      for (int j = 0; j < n - 1; j++) {
            if (i % 2 == 0) printf("*");
            else printf("-");
        }
        
      printf("\n\n");
    }

    return 0;
}
