/*
#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d",&x);
    y=x+2;
    if(y>7)printf("%d",y%7);
    else printf("%d",y);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int h;
    scanf("%d",&h);
    double x;
    x=(h-100)*0.9*2;
    printf("%.1f",x);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x,y,s;
    scanf("%d %d",&x,&y);
    s=5000-0.5*x*y-y*(100-x)-0.5*(100-x)*(100-y);
    printf("%d",s);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int x,y,z;
    x=N/15;
    y=N/20;
    z=N*10*9;
    printf("%d %d %d",x,y,z);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n,k,m,x;
    scanf("%d %d %d",&n,&k,&m);
    x=n-k*m;
    printf("%d",x);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n,x,y,z;
    scanf("%d %d %d %d",&n,&x,&y,&z);
    int a,b,c;
    a=n-x-z;
    b=y-n+x+z;
    c=n-y-x;
    printf("%d %d %d",a,b,c);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    double x,y,z;
    scanf("%lf %lf %lf",&x,&y,&z);
    double a,b,c;
    a=(y-x)/(z-1);
    b=z*(y-x)/(z-1);
    c=y+a;
    printf("%.2f %.2f %.2f",a,b,c);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    double x;
    scanf("%lf",&x);
    double y;
    if(x<0)printf("Invalid Value!");
    else
    {
        if(x>=0&&x<=50)y=0.53*x;
        else y=0.53*50+0.58*(x-50);
        printf("cost = %.2f",y);
    }
    return 0;
}
*/
