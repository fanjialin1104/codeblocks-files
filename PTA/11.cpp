/*
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n<2)
        printf("None");
    else
    {
        printf("3");
        int x;
        for(int i=3;i<=n;i++)
        {
            x=pow(2,i)-1;
            int flag=0;
            for(int j=3;j<x;j++)
                if(x%j==0)
                    flag++;
            if(flag==0)
                printf("\n%d",x);
        }
    }
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d/%d",&m,&n);
    int x=1;
    for(int i=2;i<=m;i++)
    {
        if(m%i==0&&n%i==0)
            x=i;
    }
    m/=x;
    n/=x;
    printf("%d/%d",m,n);
    return 0;
}
*//*
#include <stdio.h>
int main()
{
    char s[100];
    char *pinyin[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    scanf("%s", s);
    int i = 0;
    // 判断负号
    if(s[0] == '-')
    {
        printf("fu");
        i = 1;
    }
    else
    {
        // 第一个数字，不输出前面空格
        int num = s[0] - '0';
        printf("%s", pinyin[num]);
        i = 1;
    }
    // 处理剩下字符，前面加空格
    for(; s[i]!='\0'; i++)
    {
        int num = s[i] - '0';
        printf(" %s", pinyin[num]);
    }
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    long long n;
    scanf("%lld",&n);
    long long m=1;
    while(m*2<=n)
        m*=2;
    printf("%lld",m);
    return 0;
}
*//*
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    long long p = (long long)n * (2 * n + 1); // 防止n=1e4溢出
    // 第一行：前n+1项
    for(long long i = p; i <= p + n; i++)
    {
        if(i != p) printf(" + ");
        printf("%lld^2", i);
    }
    printf(" =\n");
    // 第二行：后n项
    for(long long i = p + n + 1; i <= p + 2*n; i++)
    {
        if(i != p + n + 1) printf(" + ");
        printf("%lld^2", i);
    }
    printf("\n");
    return 0;
}
*//*
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    char l;
    scanf("%d %c",&n,&l);
    int m=sqrt((n+1)/2);
    for(int i=m;i>0;i--)
    {
        for(int j=1;j<=m-i;j++)
            printf(" ");
        for(int j=1;j<=2*i-1;j++)
            printf("%c",l);
        printf("\n");
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=m-i;j>0;j--)
            printf(" ");

        for(int j=2*i-1;j>0;j--)
            printf("%c",l);
        printf("\n");
    }
    int x=n-2*m*m+1;
    printf("%d",x);
    return 0;
}
*//*
#include <stdio.h>

int main() {
    char c;
    int len = 0;
    int arr[1000];
    int cnt = 0; // 记录单词个数

    while (scanf("%c", &c) == 1) {
        if (c == '.') {
            // 读到结束点，还有未保存单词
            if (len > 0) {
                arr[cnt++] = len;
            }
            break;
        }
        if (c == ' ') {
            if (len > 0) {
                arr[cnt++] = len;
                len = 0;
            }
            // len=0代表连续空格，什么都不做
        } else {
            len++;
        }
    }

    // 输出，处理末尾不能有空格
    for (int i = 0; i < cnt; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
    return 0;
}
*//*
#include<stdio.h>
int main()
{
    int n;
    int m=0;
    scanf("%d",&n);
    int a[20];
    a[0]=n;
    for(int i=0;;i++)
    {
        a[i+1]=0;
        int t=a[i];
        while(t>0){
            a[i+1]+=t%10;
            t/=10;
        }
        a[i+1]=a[i+1]*3+1;
        if(i==0)
            printf("%d:%d",i+1,a[i+1]);
        else
            printf("\n%d:%d",i+1,a[i+1]);
        if(a[i+1]==a[i])
            break;
    }
    return 0;
}
*//*
#include <stdio.h>
#include <math.h>

int main()
{
    long long N;
    scanf("%lld", &N);
    long long max_len = 0, start = 0;
    long long sqrt_n = sqrt(N);

    // 枚举起点i
    for (long long i = 2; i <= sqrt_n; i++)
    {
        long long product = 1;
        long long j;
        for (j = i; product * j <= N; j++)
        {
            product *= j;
            if (N % product == 0)
            {
                // 更新最长序列
                if (j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    start = i;
                }
            }
            else
            {
                break;
            }
        }
    }

    if (max_len == 0)
    {
        // 质数情况
        printf("1\n%lld\n", N);
    }
    else
    {
        printf("%lld\n", max_len);
        for (long long i = 0; i < max_len; i++)
        {
            if (i > 0) printf("*");
            printf("%lld", start + i);
        }
        printf("\n");
    }
    return 0;
}
*/
#include<stdio.h>
int main()
{

    return 0;
}
