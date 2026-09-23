/*
#include<stdio.h>
int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    double c;
    if(B==0)
        printf("%d/%d=Error",A,B);
    else
        {
        c=A*1.00/B;
        if(B>0)
            printf("%d/%d=%.2f",A,B,c);
        else
            printf("%d/(%d)=%.2f",A,B,c);
        }

    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int Pa,Pb,a[3];
    scanf("%d %d",&Pa,&Pb);
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    int xa=0;
    int xb=0;
    for(int i=0;i<3;i++)
    {
        if(a[i]==0)
            xa++;
        else
            xb++;
    }
    if(Pa+xa>Pb+xb&&xa>0||xa==3)
        printf("The winner is a: %d + %d",Pa,xa);
    else
        printf("The winner is b: %d + %d",Pb,xb);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    double x,y;
    scanf("%lf %lf",&x,&y);
    double z;
    z=x/(y*y);
    printf("%.1f\n",z);
    if(z>25)
        printf("PANG");
    else
        printf("Hai Xing");
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    int yy=y/100*60+y%100;
    int xx=x/100*60+x%100;
    int z=yy-xx;
    int hh=z/60;
    int mm=z%60;
    printf("%02d:%02d",hh,mm);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d:%d",&x,&y);
    if(x>=12)
    {
        if(x>=13)
            x-=12;
        printf("%d:%d PM",x,y);
    }
    else
        printf("%d:%d AM",x,y);
    return 0;
}
*/
#include<stdio.h>
int main()
{

    return 0;
}
