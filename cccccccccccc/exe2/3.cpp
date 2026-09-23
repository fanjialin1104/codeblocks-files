#include<stdio.h>
int main()
{
    int m,n,i,t,a;
    scanf("%d %d",&m,&n);
    i=m;
    t=0;
    while(i<=n)
    {
        if(i%3==2&&i%5==3&&i%7==4)
        {
            printf("%d",i);
            ++t;
            for(a=0;a<t;a++)
              printf(" ");
        }

        i++;
    }
    printf("\n%d",t);
    return 0;
}
