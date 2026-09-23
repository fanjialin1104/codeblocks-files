#include<iostream>
using namespace std;

//你提交的代码在这里
class Complex
{
private:
    double r,i;
public:
    Complex(){r=1;i=2;}
    Complex(double real,double imag){r=real;i=imag;}
    void Set(double real,double imag){r=real;i=imag;}
    void Show()
    {
        if(i==0)
            cout<<r<<endl;
        if(r==0&&i!=0)
            cout<<i<<"i"<<endl;
        if(r!=0&&i>0)
            cout<<r<<"+"<<i<<"i"<<endl;
        if(r!=0&&i<0)
            cout<<r<<i<<"i"<<endl;
    }
};


int main()
{
    Complex c1;
    cout<<"Show object c1:";
    c1.Show();
    double real,imag;
    cin>>real>>imag;
    Complex c2(real,imag);
    cout<<"Show object c2:";
    c2.Show();
    cin>>real>>imag;
    cout<<"Reset and Show object c1:";
    c1.Set(real,imag);
    c1.Show();
    return 0;
}
