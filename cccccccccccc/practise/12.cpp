#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int x=1;
    for(int i=N;i>1;i--)
    {
       x=(x+1)*2;
    }
    printf("%d",x);
    return 0;
}
