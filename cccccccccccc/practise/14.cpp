/*#include<stdio.h>
int main()
{
  int m,n;
  scanf("%d %d",&n,&m);
  int i,j,score[n][m+1];
  float ave[m+1];
  char name[n][10];
  for(i=0;i<n;i++)
  {
    scanf("%s",name[i]);
    for(j=0;j<=m;j++)
      scanf("%d",&score[i][j]);
  }
  for(i=0;i<n;i++)
  {
    score[i][0]=0;
    for(j=1;j<=m;j++)
      score[i][0]+=score[i][j];
  }
  for(j=1;j<=m;j++)
  {
    ave[j]=0;
    for(i=0;i<n;i++)
      ave[j]+=score[i][j];
    ave[j]/=n;
  }
  for(i=0;i<n;i++)
  {
    printf("%-8s ",name[i]);
    for(j=0;j<=m;j++)
      printf("%6d",score[i][j]);
    printf("\n");
  }
  printf("average score:");
  for(i=1;i<=m;i++)
    printf("%6.1f",ave[i]);
  printf("\n");
  return 0;
}*/
/*
#include<stdio.h>
int main()
{
  int a[10]={0};
  while(1)
  {
    if(getchar()=='!')
      break;
    for(int i=0;i<10;i++)
      if(getchar()=='i')
        a[i]++;
  }
  for(int i=0;i<10;i++)
    printf("The character %d appears %d times\n",i,a[i]);
  return 0;
}
*/#include <stdio.h>

double maxVal(double, double, double);
int main()
{

    double x, y, z;
    scanf("%lf %lf %lf", &x, &y,&z);


double m,a,b,c;
m=maxVal(a,b,c)/(maxVal(a+b,b,c)*maxVal(a,b,b+c));
printf("%.2f",m);


    return 0;
}
double maxVal(double a,double b, double c)
{
  double t;
  t=a>b?a:b;
  double m;
  m=t>c?t:c;
  return m;
}
