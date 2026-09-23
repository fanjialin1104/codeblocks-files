#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main()
{
    int c=8;
    system("color 0c");
    string str="I IOVE YOU!";
    for(float i=2;i>-2.0;i-=0.12)
    {
        for(float j=-2.5;j<2.1;j+=0.05)
        {
            float a=i*i+j*j-4;
            if(a*a*a-j*j*i*i<-0.0)
            {
                int n=c%str.length();
                putchar(str.at(n));
                c++;
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
