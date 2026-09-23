#include <stdio.h>
void sub(int a[],int b[],int c[],int m,int n);
int main()
{
    int i,x[5]= {1,2,3,8,9},y[3]= {-1,4,6},z[8];
    sub(x,y,z,5,3);
    printf("%d",z[0]);
    for(i=1; i<8; i++)
        printf(" %d",z[i]);
}

void sub(int a[],int b[],int c[],int m,int n)
{
    int i,j;
    for(i=0; i<m; i++)
        c[i]=a[i];
    for(j=0; j<n; j++,i++)
        c[i]=b[j];
}
