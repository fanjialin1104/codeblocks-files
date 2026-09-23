#include<stdio.h>
long long  my_pow(int a,int b)
{
  long long x=1;
  for(int i=1;i<=b;i++)
    x*=a;
  return x;
}
int main()
{
  int N;
  scanf("%d",&N);
  for(int i=my_pow(10,N-1);i<my_pow(10,N);i++)
  {
      long long sum=0;
      long long t,m=i;
     while(m>0£©
    {
        t=m%10;
        m=m/10;
        sum+=my_pow(t,N);
    }
    if(sum==i)
        printf("%11d\n",i);
   }
   return 0;
}

