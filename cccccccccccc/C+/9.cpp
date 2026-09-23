//2006.7.11À¢Ã‚
/*
#include<iostream>
using namespace std;
class Clock
{
private:
    int hour,minute,second;
public:
    Clock(){hour=8;minute=16;second=24;}
    Clock(int h,int m,int s){hour=h;minute=m;second=s;}
    void Set(int h,int m, int s){hour=h;minute=m;second=s;}
    void Show(){cout<<hour<<":"<<minute<<":"<<second<<"\n";}
};

int main()
{
    Clock c1,c2(12,25,38);
    cout<<"Show object c1:";
    c1.Show();
    cout<<"Show object c2:";
    c2.Show();
    int h,m,s;
    cin>>h>>m>>s;
    cout<<"Reset and Show object c1:";
    c1.Set(h,m,s);
    c1.Show();
    cin>>h>>m>>s;
    cout<<"Reset and Show object c2:";
    c2.Set(h,m,s);
    c2.Show();
    return 0;
}
*//*
#include<iostream>
using namespace std;
class Point
{
private:
    int x,y;
public:
    Point():x(10),y(16){}
    Point(int xx,int yy):x(xx),y(yy){}
    void Set(int xx,int yy){x=xx;y=yy;}
    void Show(){cout<<"("<<x<<","<<y<<")"<<"\n";}
};
int main()
{
    Point p1,p2(20,100);
    cout<<"Show object p1:";
    p1.Show();
    cout<<"Show object p2:";
    p2.Show();
    int x,y;
    cin>>x>>y;
    cout<<"Reset and Show object p1:";
    p1.Set(x,y);
    p1.Show();
    cin>>x>>y;
    cout<<"Reset and Show object p2:";
    p2.Set(x,y);
    p2.Show();
    return 0;
}
*/
#include<iostream>
using namespace std;
class Circle
{
private:
    double radius;
public:
    Circle(){radius=10;}
    Circle(double r):radius(r){}
    void Set(double r){radius=r;}
    double Get(){return radius;}
    double Circumference(){return 2*3.14*radius;}
    double Square(){return 3.14*radius*radius;}

};
int main()
{
    Circle c1;
    cout<<"Show object c1:"<<endl;
    cout<<"    radius="<<c1.Get()<<endl;
    cout<<"    Circumference="<<c1.Circumference()<<endl;
    cout<<"    Square="<<c1.Square()<<endl;
    double r;
    cin>>r;
    Circle c2(r);
    cout<<"Show object c2:"<<endl;
    cout<<"    radius="<<c2.Get()<<endl;
    cout<<"    Circumference="<<c2.Circumference()<<endl;
    cout<<"    Square="<<c2.Square()<<endl;
    cin>>r;
    cout<<"Reset and Show object c1:"<<endl;
    c1.Set(r);
    cout<<"    radius="<<c1.Get()<<endl;
    cout<<"    Circumference="<<c1.Circumference()<<endl;
    cout<<"    Square="<<c1.Square()<<endl;
    return 0;
}
