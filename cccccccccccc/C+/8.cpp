#include<iostream>
using namespace std;
class Point{
private:
    double x,y;
public:
    Point(double xx,double yy){x=xx;y=yy;}
    double GetX(){return x;}
    double GetY(){return y;}
    void Show(){cout<<"("<<x<<","<<y<<")";}
};
