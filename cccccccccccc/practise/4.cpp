/*#include<stdio.h>
int main()
{
  int n;
  int a=0,b=1;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
      b=a+b;
      a=b-a;
      printf("%10d",a);
  }
  return 0;
}*/
/*#include<stdio.h>
#include<math.h>
int main()
{

    double x,y,z;
    scanf("%lf",&x);
    if(x<=2.5)
        y=x*x+1;
    else
        y=x*x-1;
    printf("%f\n",y);
    if(x<0)
        z=-M_PI/2*x+1;
    else if(x>0)
        z=M_PI/2*x-5;
    else
        z=0;
    printf("%f",z);
    return 0;
}*/

#include <stdio.h>

int main() {
    float s1, s2, s3, avg;
    printf("输入三科成绩：");
    scanf("%f%f%f", &s1, &s2, &s3);
    avg = (s1 + s2 + s3) / 3;
    int grade = avg / 10;
    switch(grade) {
        case 10:
        case 9: printf("甲等"); break;
        case 8: printf("乙等"); break;
        case 7: printf("丙等"); break;
        default: printf("无奖学金");
    }
    return 0;
}
