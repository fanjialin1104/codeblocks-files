/*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n<=2000||n>2100)
        printf("Invalid year!");
    else if(n>2000&&n<2004)
        printf("None");
    else
    {
        printf("2004");
        for(int i=2004;i<=n;i+=4)
        {
            if(i!=2004&&((i%4==0&&i%100!=0)||i%400==0))
                printf("\n%d",i);
        }
    }
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int count= 0;
    int fen5,fen2,fen1;
    for(fen5=x/5;fen5>0;fen5--)
    {
        for(fen2=(x-fen5*5)/2;fen2>0;fen2--)
        {
            fen1=x-fen5*5-fen2*2;
            if(fen1>0)
            {
                count++;
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",fen5,fen2,fen1,fen5+fen2+fen1);
            }
        }
    }
    printf("count = %d",count);
    return 0;
}
*/
#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d", &N);
    int start = pow(10, N - 1);
    int end = pow(10, N) - 1;
    int arr[100];
    int cnt = 0;

    // 先收集所有水仙花数
    for(int num = start; num <= end; num++)
    {
        int temp = num;
        int sum = 0;
        while(temp > 0)
        {
            int digit = temp % 10;
            sum += pow(digit, N);
            temp = temp / 10;
        }
        if(sum == num)
        {
            arr[cnt++] = num;
        }
    }
    // 打印
    for(int i = 0; i < cnt; i++)
    {
        if(i != cnt - 1)
            printf("%d\n", arr[i]);
        else
            printf("%d", arr[i]);
    }
    return 0;
}
/*
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int )
    return 0;
}
