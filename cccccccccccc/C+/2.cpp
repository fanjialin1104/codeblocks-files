/*
#include<iostream>
using namespace std;

//你提交的代码在这里
class Clock
{
private:
    int hour,minute,second;
public:
    Clock()
    {
        hour=8;
        minute=16;
        second=24;
    }
    Clock(int h,int m,int s)
    {
        hour=h;
        minute=m;
        second=s;
    }
    void Set(int h,int m,int s)
    {
       hour=h;
       minute=m;
       second=s;
    }
    void Show()
    {
       cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
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
#include<iomanip>
using namespace std;
class Fixed_Deposit {
private:
    double amount;   // 本金
    double rate;     // 利率
    int years;       // 存款年数
public:
    // 无参构造：初始化默认值，对应 Fixed_Deposit f1;
    Fixed_Deposit() : amount(10000.00), rate(0.033), years(1) {}

    // 带参构造：对应 Fixed_Deposit f2(amount, rate, years);
    Fixed_Deposit(double a, double r, int y) : amount(a), rate(r), years(y) {}

    // 获取本金
    double GetAmount() const {
        return amount;
    }

    // 获取利率
    double GetRate() const {
        return rate;
    }

    // 获取年数
    int GetYears() const {
        return years;
    }

    // 计算本息合计：本金 + 本金×年数×利率
    double GetAll() const {
        return amount + amount * years * rate;
    }

    // Set方法：重置存款信息
    void Set(double a, double r, int y) {
        amount = a;
        rate = r;
        years = y;
    }

    // Show方法：严格按样例格式输出，不额外加换行
    void Show() const {
        cout << "amount=" << amount
             << " rate=" << rate * 100 << "%"
             << " years=" << years
             << " total=" << GetAll() << endl;
    }
};
int main()
{
    cout<<fixed<<setprecision(2);
    Fixed_Deposit f1;
    cout<<"Show object f1:"<<endl;
    cout<<"amount="<<f1.GetAmount();        //输出存款本金
    cout<<"  rate="<<f1.GetRate()*100<<"%"; //输出存款利率
    cout<<"  years="<<f1.GetYears();        //输出存款年数
    cout<<"  total="<<f1.GetAll()<<endl;    //输出到期本息合计
    double amount,rate;
    int years;
    cin>>amount>>rate>>years;
    Fixed_Deposit f2(amount,rate,years);
    cout<<"Show object f2:"<<endl;
    cout<<"amount="<<f2.GetAmount();        //输出存款本金
    cout<<"  rate="<<f2.GetRate()*100<<"%"; //输出存款利率
    cout<<"  years="<<f2.GetYears();        //输出存款年数
    cout<<"  total="<<f2.GetAll()<<endl;    //输出到期本息合计
    cin>>amount>>rate>>years;
    cout<<"Reset and Show object f1:"<<endl;
    f1.Set(amount,rate,years);
    f1.Show();
    return 0;
}
*/
