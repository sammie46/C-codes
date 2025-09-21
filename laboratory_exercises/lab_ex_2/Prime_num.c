#include <stdio.h>
#include <stdlib.h>

int main()
{
 int n;
 scanf("%d",&n);
 int count;
 for (int i = 1; i<=n; i++){
    if (n % i == 0){
        count += 1;
    }
    else{
        count = count;
    }
 }

 if (count == 2 ){
    printf("The number is prime!");
 }
else
 {
     printf("The number is not prime!");
 }
    return 0;
}
