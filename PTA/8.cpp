/*
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    double a[n];
    double sum=0;
    for(int i=0;i<n;i++)
    {
        a[i]=pow(-1,i)*(i+1)/(2*i+1);
        sum+=a[i];
    }
    printf("%.3f",sum);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    double a[n];
    double sum=1;
    for(int i=0;i<n;i++)
    {
        if(i==0)
            a[i]=1;
        else
            a[i]=(i+1)*a[i-1];
        sum+=1.00000000/a[i];
    }
    printf("%.8f",sum);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int a,n;
    scanf("%d %d",&a,&n);
    int sum=0;
    int m=0;
    for(int i=0;i<n;i++)
    {
        m=m*10+a;
        sum+=m;
    }
    printf("s = %d",sum);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a=1;
    for(int i=1;i<n;i++)
    {
        a=(1+a)*2;
    }
    printf("%d",a);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n<2)
    {
        printf("1");
        return 0;
    }
    int month=2;
    int a=1,b=1;
    int c;
    while(b < n)
    {
        c = a + b;
        a = b;
        b = c;
        month++;
    }
    printf("%d",month);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int x=m*n;
    int a=0;
    while(x!=0)
    {
        a=x%10+10*a;
        x=x/10;
    }
    printf("%d",a);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int sum=0;
    int x;
    while(1)
    {
        scanf("%d",&x);
        if(x<=0)
            break;
        if(x%2==1)
            sum+=x;
    }
    printf("%d",sum);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n/2+1;i++)
    {
        for(int j=0;j<n/2+1-i;j++)
            printf("  ");
        for(int j=1;j<=2*i-1;j++)
            printf("* ");
        printf("\n");
    }
    for(int i=1;i<=n/2;i++)
    {
        for(int j=1;j<=i;j++)
            printf("  ");
        for(int j=0;j<n-2*i;j++)
            printf("* ");
        if(i!=n/2)
            printf("\n");
    }
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int sex[n],h[n],w[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&sex[i],&h[i],&w[i]);
        if(sex[i]==0)
        {
            if(h[i]<129)
                printf("duo chi yu! ");
            else if(h[i]==129)
                printf("wan mei! ");
            else
                printf("ni li hai! ");
            if(w[i]<25)
                printf("duo chi rou!");
            else if(w[i]==25)
                printf("wan mei!");
            else
                printf("shao chi rou!");
        }
        else
        {
            if(h[i]<130)
                printf("duo chi yu! ");
            else if(h[i]==130)
                printf("wan mei! ");
            else
                printf("ni li hai! ");
            if(w[i]<27)
                printf("duo chi rou!");
            else if(w[i]==27)
                printf("wan mei!");
            else
                printf("shao chi rou!");
        }
        if(i!=n)
            printf("\n");
    }
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b)
{
    a = llabs(a);
    b = llabs(b);
    while (b != 0)
    {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);
    long long up = 0, down = 1;
    for (int i = 0; i < n; i++)
    {
        long long a, b;
        scanf("%lld/%lld", &a, &b);
        up = up * b + a * down;
        down = down * b;
        long long g = gcd(up, down);
        up /= g;
        down /= g;
    }
    long long integer = up / down;
    long long frac_up = up % down;

    if (frac_up == 0)
    {
        printf("%lld", integer);
    }
    else
    {
        if (integer != 0)
        {
            printf("%lld ", integer);
        }
        printf("%lld/%lld", frac_up, down);
    }
    return 0;
}
/*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    double sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d/%d",&a[i],&b[i]);
        sum+=
    }
    return 0;
}
*/
