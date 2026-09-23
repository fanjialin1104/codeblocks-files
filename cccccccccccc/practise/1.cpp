#include<stdio.h>
int main()
{
  long long n;
  scanf("%11d",&n);
  double x;
  int a=1,b=1;
  for(int i=1;i<=n;i++)
  {
    a=b;
    b=a+b;
    x+=b/a;
  }
  printf("%.6f",x);
  return 0;
}
