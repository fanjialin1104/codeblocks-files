#include<stdio.h>
int main()
{
    double a=1,b=1,n;
    scanf("%d",&n);
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        b=a+b;
        a=b-a;
        sum+=b/a;
    }
    printf("%.6f",sum);
    return 0;
}
