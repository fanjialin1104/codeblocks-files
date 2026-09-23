#include<stdio.h>
int main()
{
    int N,x=1,y=0;
  scanf("%d",&N);
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=i;j++)
      x=x*j;
    y+=x;
  }
  printf("%d",y);
  return 0;
}
