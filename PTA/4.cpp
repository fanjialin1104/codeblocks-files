/*
#include<stdio.h>
#include<string.h>
int main()
{
    int sum=0;
    char str[3];
    for(int i=0;i<=2;i++)
    {
        scanf(" %c",&str[i]);
        sum+=str[i];
    }
    for(int i=2;i>=0;i--)
    {
        printf("%c",str[i]);
        if(i!=0)printf(" ");
    }
    printf("\n%d",sum);
    return 0;
}
*//*
#include<stdio.h>
#include<math.h>
int main()
{
    double money,year;
    double rate,interest;
    scanf("%lf %lf %lf",&money,&year,&rate);
    interest=money*pow(1+rate,year)-money;
    printf("interest = %.2f",interest);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int foot,inch;
    double m=x/30.48;
    foot=x/30.48;
    inch=(m-foot)*12;
    printf("%d %d",foot,inch);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int m;
    scanf("%d",&m);
    int x,y,z;
    x=m%10;
    y=m/10%10;
    z=m/100;
    if(x==0&&y!=0)
        printf("%d%d",y,z);
    else if(x==0&&y==0)
        printf("%d",z);
    else
        printf("%d%d%d",x,y,z);
    return 0;
}
*/
