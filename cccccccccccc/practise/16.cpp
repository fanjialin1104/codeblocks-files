/*#include<stdio.h>
int main( )
{
    char str[80]="neieeheaeeo!",k='e',i,j;
    for(i=j=0; str[i]!='\0'; i++)
        if(str[i]!= k) str[j++]=str[i];
    str[j]='\0';
    puts(str);
    return 0;
}

#include <stdio.h>
int main( )
{
    static int a[][3]={9,7,5,3,1,2,4,6,8};
    int i, j, s1=0, s2=0;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
        {
            if( i==j )   s1=s1+a[i][j];
            if( i+j==2)  s2=s2+a[i][j];
        }
    printf("%d %d", s1, s2) ;
    return 0;
}*/
int main( )
{
    char b[17] = "0123456789ABCDEF";
    int c[64], n, i=0, base=16;

    n=1524233136;
    do{
            c[i] = n%base;
            i++;
            n=n/base;
    } while (n!=0);

    for( --i ; i>=0 ; --i )
        printf("%c", b[ c[i] ] );
    return 0;
}
