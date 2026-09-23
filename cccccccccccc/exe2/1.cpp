#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    if(n<=1)
    {
        printf("%d不是质数",n);
        return 0;
    }
    for(i=2;i<n;i++)
   {
      if(n%i==0)
      {
         printf("%d不是质数",n);
         break;
      }
    }
    if(i==n)
      printf("%d是质数",n);
    return 0;
}
