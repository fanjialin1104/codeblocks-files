/*
#include<stdio.h>
int f(int x,int y)
{
    if(y==0)
        return x;
    return f(y,x%y);
}
int main()
{
   int a,b;
   scanf("%d %d",&a,&b);
   int m=f(a,b);
   printf("%d",m);
   return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[32],m=0;
    for(int i=1;n>0;i++)
    {
        a[i]=n%2;
        n=n/2;
        m++;
    }
    for(int j=m;j>0;j--)
        printf("%d",a[j]);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
        {
           int t;

          if(a[j]>a[j+1])
    {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
    }
        }
    for(int i=0;i<n;i++)
        printf("%d",a[i]);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    char from[80],to[80];
    gets(from);
    int i;
    for(i=0;from[i]!='\0';i++)
        to[i]=from[i];
    to[i]='\0';
    puts(to);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    char s1[80],s2[80];
    gets(s1);
    gets(s2);
    int i,j;
    for(i=0;s1[i]!='\0';i++)
        ;
    for(j=0;s2[j]!='\0';j++)
        s1[i+j]=s2[j];
    s1[i+j]='\0';
    puts(s1);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    char s[80],ch;
    int i,j;
    gets(s);
    ch=getchar();
    for(i=0,j=0;s[i]!='\0';i++)
        if(s[i]!=ch)
            s[j++]=s[i];
        s[j]='\0';
        puts(s);
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int a[5]={1,3,5,7};
    int x,i,j;
    scanf("%d",&x);
    for(i=0;i<4;i++)
        if(x<=a[i])
          break;
    for(j=3;j>=i;j--)
    {
        a[i+1]=a[i];
        a[i]=x;
    }
     for(int m=0;m<5;m++)
        printf("%d",a[m]);
    return 0;
}
*/
#include<stdio.h>
int main()
{
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int *pi,*pj,t;
    pi=a,pj=a+9;
    while(pi<pj)
    {
      t=*pi;
      *pi=*pj;
      *pj=t;

    }
    for(int m=0;m<10;m++)
        printf("%d",a[m]);
    return 0;
}
