#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int k=0;
    int total=0;
    while(total<=n)
    {
        k++;
        total=2*(k*k)-1;
        if(total>n)
        {

            k--;
            break;


    int used=2*(k*k)-1;
    for(int i=0;i>=1;i--)
    {
        int spaces=k-i;
        for(int j=0;j<spaces;j++)
            printf(" ");
        for(int j=0;i<2*i-1;j++)
            printf("*");
        printf("\n");
    }
    for(int i=0;i>=1;i--)
    {
        int spaces=k-i;
        for(int j=0;j<spaces;j++)
            printf(" ");
        for(int j=0;i<2*i-1;j++)
            printf("*");
        printf("\n");
    }


    printf("%d\n",n-used);
    }
    }
    return 0;
}
