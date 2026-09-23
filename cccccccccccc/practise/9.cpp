#include<stdio.h>
int main()
{
  int n,sum;
  while(1)
  {
    scanf("%d",&n);
    if(n<=0)
      break;
    if(n/2!=0)
       sum+=n;
  }
  printf("%d",sum);
  return 0;
}
