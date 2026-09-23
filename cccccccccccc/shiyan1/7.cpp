#include<stdio.h>
int main()
{
    double x,y,z;
    scanf("%lf %lf %lf",&x,&y,&z);
    double a,b;
    a=(x+y+z)/3;
    b=x*y*z;
    printf("%f %f",a,b);
    return 0;
}
