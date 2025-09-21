#include <stdio.h>
#include <stdlib.h>

int main()
{

  float a,b;
  
  scanf("%f %f",&a,&b);
  
  float sum,sub,mult,del;

  sum=a+b;
  sub=a-b;
  mult=a*b;
  del=a/b;
  
  printf("Subirane na a i b: %f\n",sum);
  printf("Izwajdane na a i b: %f\n",sub);
  printf("Umnojenie na a i b: %f\n",mult);
  printf("Delenie na a i b: %f\n",del);


    return 0;
}
