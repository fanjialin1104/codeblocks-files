#include <stdio.h>

int main ( )
{
       int x=100, a=10, b=20, ok1=1, ok2=0 ;
       if(a<b)
            if(b !=15)
            {
                 if(!ok1)  x=1;
                 else if(ok2) x=10;
                 else x=-1;
            }
       printf("%d\n", x);
       return 0;
}
