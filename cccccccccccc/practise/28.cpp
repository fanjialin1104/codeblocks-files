#include<stdio.h>
#include<string.h>
#define MAX_STRINGS 100
#define MAX_LENGTH 100
int main()
{
  int n;
  char strings[MAX_STRINGS][MAX_LENGTH];
  char max_string[MAX_LENGTH];
  scanf("%d",&n);
  for(int i=1;i<n;i++)
  {
    scanf("%s",strings[i]);
    if(strcmp(strings[i],max_string)>0)
      strcpy(max_string,strings[i]);
  }
  printf("%s\n",max_string);
  return 0;
}
