/*
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[100];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int *left=arr;
    int *right=arr+n-1;
    int t;
    while(left<right)
    {
        t=*left;
        *left=*right;
        *right=t;
        left++;
        right--;
    }
    for(int i=0;i<n;i++)
        printf("%d",arr[i]);
    printf("\n");
    return 0;
}
*/
