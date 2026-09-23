/*
#include<stdio.h>
int main()
{
    int T,S,t;
    scanf("%d %d %d",&T,&S,&t);
    if(T>35&&t>=33&&S==1)
        printf("Bu Tie\n%d",T);
    else if(T>35&&t>=33&&S==0)
        printf("Shi Nei\n%d",T);
    else if(S==1&&(T<35||t<33))
        printf("Bu Re\n%d",t);
    else
        printf("Shu Shi\n%d",t);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int y,h;
    if(x<10000)
    {

    y=x/100;
    h=x%100;
    if(y<22)
        y=2000+y;
    else
        y=1900+y;
    }
    else
    {
        y=x/100;
        h=x%100;
    }
    printf("%d-%.2d",y,h);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x,y,h1,h2;
    scanf("%d %d %d %d",&x,&y,&h1,&h2);
    if(h1>=x&&h2>=x)
       printf("%d-Y %d-Y\nhuan ying ru guan",h1,h2);
    else if(h1<x&&h2<x)
        printf("%d-N %d-N\nzhang da zai lai ba",h1,h2);
    else if((h1>=x&&h1<y)&&h2<x)
        printf("%d-Y %d-N\n1: huan ying ru guan",h1,h2);
    else if((h2>=x&&h2<y)&&h1<x)
        printf("%d-N %d-Y\n2: huan ying ru guan",h1,h2);
    else if(h1>=y&&h2<x)
            printf("%d-Y %d-Y\nqing 1 zhao gu hao 2",h1,h2);
    else
        printf("%d-Y %d-Y\nqing 2 zhao gu hao 1",h1,h2);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int w[4];
    char id[4]={'A','B','C','D'};
    scanf("%d %d %d %d",&w[0],&w[1],&w[2],&w[3]);
    int normal;
    if(w[0]==w[1]||w[0]==w[2]||w[0]==w[3])
        normal=w[0];
    else
        normal=w[1];
    for(int i=0;i<4;i++)
    {
        if(w[i]!=normal)
        {
            if(w[i]<normal)
                printf("%c %d Too light!",id[i],w[i]);
            else
                printf("%c %d Too heavy!",id[i],w[i]);
        }
    }
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n%5>3||n%5==0)
        printf("Drying in day %d",n);
    else
        printf("Fishing in day %d",n);
    return 0;
}
*//*
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int s=sqrt(n);
    if(s*s==n)
        printf("%d\n",s-1);
    else
        printf("None\n");
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    if(x>=90)
        printf("gong xi ni kao le %d fen!",x);
    else
        printf("kao le %d fen bie xie qi!",x);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int a[4],x,y;
    for(int i=0;i<4;i++)
        scanf("%d",&a[i]);
    scanf("%d %d",&x,&y);
    int id[4]={1,2,3,4};
    int maxx=a[0],minn=a[0];
    for(int i=0;i<4;i++)
    {
        if(maxx<a[i])
            maxx=a[i];
        if(minn>a[i])
            minn=a[i];
    }
    int m=maxx-y;
    int flag=0;
    if(minn>=x&&maxx-minn<=y)
        printf("Normal");
    else
    {
        for(int i=0;i<4;i++)
        {

            if(a[i]<x||a[i]<m)
                flag++;
        }
        if(flag>=2)
            printf("Warning: please check all the tires!");
        else
        {
            for(int i=0;i<4;i++)
                if(a[i]<x||a[i]<m)
            {

                    printf("Warning: please check #%d!",id[i]);
                    break;
            }
        }
    }
    return 0;
}
*//*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int m=abs(a-c)+abs(b-d);
    printf("%d",m);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    int z;
    if(y==2)
    {

    if((x%4==0&&x%100!=0)||x%400==0)
            z=29;

    else
            z=28;
    }
    else if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)
        z=31;
    else
        z=30;
    printf("%d\n",z);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    if(x<=4)
        printf("继续加油哦!");
    else if(x>=5&&x<=10)
        printf("非常棒，继续加油哦!");
    else if(x>=11&&x<=100)
        printf("实力不容小觑啊!");
    else
        printf("能力爆表，全部通关!");
    return 0;
}
*//*
#include<stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a+b>c&&a+c>b&&b+c>a)
    {

        if(a==b&&a==c)
            printf("Equilateral triangle");
        else if(a*a+b*b==c*c||b*b+c*c==a*a||a*a+c*c==b*b)
            printf("Right triangle");
        else if(a==b||a==c||b==c)
            printf("Isosceles triangle");
        else
            printf("General triangle");
    }
    else
        printf("Not a triangle");
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int y;
    if(x<=1)
        y=0;
    else if(x>1&&x<=8)
        y=10*x;
    else
    {
        y=80+15*(x-8);
        if(y>200)
            y=200;
    }
    printf("%d",y);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int r;
    int x,y,z;
    scanf("%d",&r);
    scanf("%d %d %d",&x,&y,&z);
    if(x*x+y*y+z*z<r*r)
        printf("In the Sphere.");
    else if(x*x+y*y+z*z==r*r)
        printf("On the Sphere.");
    else
        printf("Outside the Sphere.");
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    if((x>0&&y>0)||(x<0&&y<0))
        printf("like signs");
    else if(x==0&&y==0)
        printf("two zeros");
    else if((x==0&&y!=0)||(x!=0&&y==0))
        printf("one zero");
    else
        printf("unlike signs");
    return 0;
}
*//*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int aa,bb;
    aa=abs(a-1);
    bb=abs(b-c)+abs(c-1);
    if(aa<bb)
        printf("A\n");
    else if(aa>bb)
        printf("B\n");
    else
        printf("everything is alright.");
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    if(x==y&&x==z)
        printf("Unbelievable\n");
    else if(x==y||x==z||y==z)
        printf("Amazing\n");
    else
        printf("We are all different\n");
    return 0;
}
*/
#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    double m,n;
    m=-b/(2*a);
    n=sqrt(4*a*c-b*b)/(2*a);
    printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi",m,n,m,n);
    return 0;
}

