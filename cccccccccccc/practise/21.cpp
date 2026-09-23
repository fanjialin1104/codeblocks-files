/*
#include<stdio.h>
int main()
{
  int a[10]={0};
  char ch;
  while((ch=getchar())!='!')
  {
    if(ch>='0'&&ch<='9')
    {
      int i=ch-'0';
      a[i]++;
    }
  }
  for(int i=0;i<10;i++)
    printf("The character %d appears %d times\n",i,a[i]);
  return 0;
}
*/
/*
#include <stdio.h>
int main() {
    int mood[24];
    for (int i = 0; i < 24; i++) {
        scanf("%d",&mood[i]);
    }
    int time;
    while (scanf("%d", &time) != EOF && time >= 0 && time <= 23) {
        if (mood[time] > 50) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
*/
