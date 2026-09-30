/*
#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int x=1;
    int y;
    for(int i=2;i<m;i++)
    {
        if(m%i==0&&n%i==0)
            x=i;
    }
    y=m*n/x;
    printf("%d %d",x,y);
    return 0;
}
*/
#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    int count = 0;
    int a,b,c; //百位、十位、个位
    int max, min, diff;

    do
    {
        // 1. 拆分三位数字
        a = num / 100;
        b = num / 10 % 10;
        c = num % 10;

        // 2. 冒泡排序：让 a<=b<=c 升序
        int t;
        if(a > b) { t=a; a=b; b=t; }
        if(a > c) { t=a; a=c; c=t; }
        if(b > c) { t=b; b=c; c=t; }

        min = a*100 + b*10 + c;   //升序，最小数
        max = c*100 + b*10 + a;   //降序，最大数
        diff = max - min;

        count++;
        printf("%d: %d - %d = %d\n", count, max, min, diff);

        num = diff; //差值作为下一轮输入

    }while(diff != 495); //直到等于495结束

    return 0;
}
/*
#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int flag=0;
    for(int i=m;i<=n;i++)
    {
        int sum=0;
        for(int j=1;j<i;j++)
            if(i%j==0)
                sum+=j;
        if(sum==i)
        {
            flag++;
            if(flag==1)
                printf("%d =1 ",i);
            else
                 printf("\n%d =1",i);
            for(int x=2;x<i;x++)
                if(i%x==0)
                    printf("+ %d",x);
        }
    }
    if(flag==0)
        printf("None");
    return 0;
}
*/
