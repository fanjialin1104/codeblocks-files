#include<stdio.h>
int main()
{
  int m,n,x,y;
  scanf("%d %d",&m,&n);
  x=(n-2*m)/2;
  y=m-x;
  if(x>=0&&y>=0&&n%2==0&&n>2*m)
    printf("%d %d",x,y);
  else
    printf("Error");
  return 0;
}

