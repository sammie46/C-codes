#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    if ((a+b)>c && (a+c) > b && (b+c)>a){
        printf ("The triangle is real\n");

        if (a==b && a==c && b==c)
        {
            printf("The triangle is equilateral");
        }
        else if (a==b || a==c || c==b){
            printf("The triangle is isosceles");
        }
        else {printf("The triangle is many-sided ");}
    }
    else {printf("The triangle is NOT real");}

    return 0;
}
