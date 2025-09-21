#include <stdio.h>
#include <stdlib.h>

int main()
{

   int num =42;
   int *ptr=&num;
  
   printf("%d\n",num);
   printf("%p\n",(void*)&num);
    
  return 0;
}
