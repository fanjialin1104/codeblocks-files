/*
#include<iostream>
using namespace std;
class Point
{
private:
    int xx,yy;
public:
    Point(){xx=10;yy=16;}
    Point(int x,int y){xx=x;yy=y;}
    void Show(){cout<<"("<<xx<<","<<yy<<")"<<endl;}
    void Set(int x,int y){xx=x;yy=y;}
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
*//*
#include<iostream>
#include<cstring>
using namespace std;
class Person
{
private:
    char name[20];
    char sex[5];
    int age;
public:
    Person()
    {
        strcpy(name,"NULL");
        strcpy(sex,"NO");
        age=0;
    }
    Person(char x[],char y[],int z)
    {
        strcpy(name,x);
        strcpy(sex,y);
        age=z;
    }
    char *GetName()
    {
        return name;
    }
    char*GetSex()
    {
        return sex;
    }
    int GetAge()
    {
        return age;
    }
    void Set()
    {
        strcpy(name,"Unknown");
        strcpy(sex,"FM");
        age=1000;
    }
    void Set(char x[],char y[],int z)
    {
        strcpy(name,x);
        strcpy(sex,y);
        age=z;
    }
    void Show()
    {
        cout<<name<<","<<sex<<","<<age<<endl;
    }
};
int main()
{
    Person p1;
    cout<<"Show object p1:";
    cout<<p1.GetName()<<","<<p1.GetSex()<<","<<p1.GetAge()<<endl;
    char name[20],sex[10];
    int age;
    cin>>name>>sex>>age;
    Person p2(name,sex,age);
    cout<<"Show object p2:";
    cout<<p2.GetName()<<","<<p2.GetSex()<<","<<p2.GetAge()<<endl;
    cin>>name>>sex>>age;
    cout<<"Reset and Show object p1:";
    p1.Set(name,sex,age);
    p1.Show();
    cout<<"Reset and Show object p2:";
    p2.Set();
    p2.Show();
    return 0;
}
*//*
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class Book
{
private:
    char title[40];
    char author[40];
    double price;
public:
    Book()
    {
        strcpy(title, "NULL");
        strcpy(author, "NONE");
        price = 0.00;
    }
    Book(char t[], char a[], double p)
    {
        strcpy(title, t);
        strcpy(author, a);
        price = p;
    }
    char* GetTitle()
    {
        return title;
    }
    char* GetAuthor()
    {
        return author;
    }
    double GetPrice()
    {
        return price;
    }
    void Set(char t[], char a[], double p)
    {
        strcpy(title, t);
        strcpy(author, a);
        price = p;
    }
    void Set()
    {
        strcpy(title, "高等数学(第七版)上册");
        strcpy(author, "同济大学数学系");
        price = 37.70;
    }
    void Show()
    {
        cout << title << "，" << author << "，" << price<<endl;
    }
};
int main()
{
    cout<<fixed<<setprecision(2);
    Book b1;
    cout<<"Show object b1:";
    cout<<b1.GetTitle()<<"，"<<b1.GetAuthor()<<"，"<<b1.GetPrice()<<endl;
    char title[40],author[40];
    double price;
    cin>>title>>author>>price;
    Book b2(title,author,price);
    cout<<"Show object b2:";
    cout<<b2.GetTitle()<<"，"<<b2.GetAuthor()<<"，"<<b2.GetPrice()<<endl;
    cin>>title>>author>>price;
    cout<<"Reset and Show object b1:";
    b1.Set(title,author,price);
    b1.Show();
    cout<<"Reset and Show object b2:";
    b2.Set();
    b2.Show();
    return 0;
}
*//*
#include<iostream>
using namespace std;
class CTime
{
private:
    int hour, minute, second;
public:
    // #1 无参构造
    CTime() : hour(9), minute(10), second(11)
    {
        cout << "Function #1 is called!" << endl;
    }

    // #2 三参构造：时、分、秒
    CTime(int h, int m, int s) : hour(h), minute(m), second(s)
    {
        cout << "Function #2 is called!" << endl;
    }

    // #3 拷贝构造 CTime(const CTime&)
    CTime(const CTime& t)
    {
        hour = t.hour;
        minute = t.minute;
        second = t.second;
        cout << "Function #3 is called!\n" << endl;
    }

    // #4 CDate无参构造调用的基类拷贝构造配套
    // Show输出时分秒
    void Show() const
    {
        cout << hour << ":" << minute << ":" << second;
    }
};

// 派生类 CDate 公有继承 CTime
class CDate : public CTime
{
private:
    int year, month, day;
public:
    // #5 CDate无参构造：默认日期2023-4-5，基类调用无参构造#1
    CDate() : CTime(), year(2023), month(4), day(5)
    {
        cout << "Function #4 is called!\n" << endl;
    }

    // #6 三参构造(年,月,日)：基类调用无参#1
    CDate(int y, int m, int d) : CTime(), year(y), month(m), day(d)
    {
        cout << "Function #5 is called!\n" << endl;
    }

    // #7 六参构造(年,月,日,时,分,秒)：基类调用三参#2
    CDate(int y, int m, int d, int h, int mi, int s) : CTime(h, mi, s), year(y), month(m), day(d)
    {
        cout << "Function #6 is called!\n" << endl;
    }

    // #8 四参构造(年,月,日,CTime对象)：基类调用拷贝构造#3
    CDate(int y, int m, int d, const CTime& t) : CTime(t), year(y), month(m), day(d)
    {
        cout << "Function #7 is called!\n" << endl;
    }

    // #9 单参构造(CTime对象)：基类拷贝#3，默认日期2000-12-31
    CDate(const CTime& t) : CTime(t), year(2000), month(12), day(31)
    {
        cout << "Function #8 is called!\n" << endl;
    }

    // Show：输出 年-月-日 时:分:秒
    void Show() const
    {
        cout << year << "-" << month << "-" << day << " ";
        cout<<"Function #3 is called!\nFunction #9 is called!\n"<<endl;
        CTime::Show();
    }
};

int main()
{
    int dy,dm,dd,th,tm,ts;
    cin>>dy>>dm>>dd>>th>>tm>>ts;
    CTime t1;
    cout<<"[T1]";    t1.Show();
    CDate d1;
    cout<<"[D1]";    d1.Show();
    CDate d2(dy,dm,dd);
    cout<<"[D2]";    d2.Show();
    CDate d3(dy,dm,dd,th,tm,ts);
    cout<<"[D3]";    d3.Show();
    CDate d4(dy,dm,dd,t1);
    cout<<"[D4]";    d4.Show();
    CDate d5(t1);
    cout<<"[D5]";    d5.Show();
    return 0;
}
*/
#include <cstring>
#include<iostream>
using namespace std;

// 基类 Person
class Person
{
private:
    char name[40];
    char sex[3];
    int age;
public:
    // #1 Person无参构造
    Person()
    {
        cout << "Function #1 is called!\n";
        strcpy(name, "Unknown");
        strcpy(sex, "No");
        age = 0;
    }
    // #2 Person三参构造：姓名、性别、年龄
    Person(char n[], char s[], int a)
    {
        cout << "Function #2 is called!\n";
        strcpy(name, n);
        strcpy(sex, s);
        age = a;
    }
    // Person拷贝构造
    Person(const Person& p)
    {
        strcpy(name, p.name);
        strcpy(sex, p.sex);
        age = p.age;
    }
    // 供派生类读取私有成员接口
    char* GetName() { return name; }
    char* GetSex() { return sex; }
    int GetAge() const { return age; }
    // Person输出函数
    void Show() const
    {
        cout << "NAME:" << name << " SEX:" << sex << " AGE:" << age << endl;
    }
};

// 派生类 Student 公有继承 Person
class Student : public Person
{
private:
    char Class[40];
    char major[40];
    int score;
public:
    // #3 Student无参构造，默认班级NONE、专业NONE、分数100
    Student() : Person((cout << "Function #3 is called!\n", ""), "", 0)
    {
        strcpy(Class, "NONE");
        strcpy(major, "NONE");
        score = 100;
    }
    // #4 Student六参构造：姓名、性别、年龄、班级、专业、分数
    Student(char n[], char s[], int a, char cls[], char maj[], int sc)
        : Person(n, s, a)
    {
        cout << "Function #4 is called!\n";
        strcpy(Class, cls);
        strcpy(major, maj);
        score = sc;
    }
    // #5 Student五参构造：Person对象、班级、专业、分数
    Student(const Person& p, char cls[], char maj[], int sc)
        : Person(p)
    {
        cout << "Function #5 is called!\n";
        strcpy(Class, cls);
        strcpy(major, maj);
        score = sc;
    }
    // #6 Student四参构造：班级、专业、分数，Person走无参构造
    Student(char cls[], char maj[], int sc)
        : Person((cout << "Function #1 is called!\n", ""), "", 0)
    {
        cout << "Function #6 is called!\n";
        strcpy(Class, cls);
        strcpy(major, maj);
        score = sc;
    }
    // #7 Student单参构造：仅Person对象，默认班级NONE、专业NONE、分数100
    Student(const Person& p) : Person(p)
    {
        cout << "Function #7 is called!\n";
        strcpy(Class, "NONE");
        strcpy(major, "NONE");
        score = 100;
    }
    // Student输出函数
    void Show()
    {
        cout << "NAME:" << GetName() << " SEX:" << GetSex() << " AGE:" << GetAge()
             << " CLASS:" << Class << " MAJOR:" << major << " SCORE:" << score << endl;
    }
};
