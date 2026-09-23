#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

// 日期类（内嵌子对象）
class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int y = 1990, int m = 1, int d = 1) : year(y), month(m), day(d)
    {
        cout << "  Date 构造函数被调用\n";
    }
    Date(const Date& other) : year(other.year), month(other.month), day(other.day)
    {
        cout << "  Date 拷贝构造函数被调用\n";
    }
    ~Date()
    {
        cout << "  Date 析构函数被调用\n";
    }
    inline void setDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void showDate() const
    {
        printf("%04d-%02d-%02d", year, month, day);
    }
};
class Person
{
private:
    string id;
    string name;
    string gender;
    Date birthDate;
    string idCard;
public:
    Person(string pId = "000000", string pName = "Unknown", string pGender = "男",
           const Date& birth = Date(), string pIdCard = "000000000000000000")
        : id(pId), name(pName), gender(pGender), birthDate(birth), idCard(pIdCard)
    {
        cout << "Person 构造函数被调用: " << name << "\n";
    }
    Person(const Person& other)
        : id(other.id), name(other.name), gender(other.gender),
          birthDate(other.birthDate), idCard(other.idCard)
    {
        cout << "Person 拷贝构造函数被调用: " << name << "\n";
    }
    ~Person()
    {
        cout << "Person 析构函数被调用: " << name << "\n";
    }
    inline void setGender(string g)
    {
        gender = g;
    }

    void setInfo(string pId, string pName, string pGender = "男",
                 const Date& birth = Date(), string pIdCard = "000000000000000000")
    {
        id = pId;
        name = pName;
        gender = pGender;
        birthDate = birth;
        idCard = pIdCard;
    }
    void displayInfo() const
    {
        cout << "\n===== 人员信息 =====\n";
        cout << "编    号: " << id << "\n";
        cout << "姓    名: " << name << "\n";
        cout << "性    别: " << gender << "\n";
        cout << "出生日期: ";
        birthDate.showDate();
        cout << "\n身份证号: " << idCard << "\n";
        cout << "====================\n";
    }
};
int main()
{
    cout << "---------- 测试1：默认构造函数（带默认参数） ----------\n";
    Person p1;
    p1.displayInfo();

    cout << "\n---------- 测试2：带参数构造函数 ----------\n";
    Date birth(1999, 10, 5);
    Person p2("2023001", "张三", "男", birth, "420101199910051234");
    p2.displayInfo();

    cout << "\n---------- 测试3：拷贝构造函数 ----------\n";
    Person p3 = p2;
    p3.displayInfo();

    cout << "\n---------- 测试4：带默认参数的成员函数setInfo ----------\n";
    p1.setInfo("2023002", "李四");
    p1.displayInfo();

    cout << "\n---------- 测试5：内联成员函数setGender ----------\n";
    p1.setGender("女");
    p1.displayInfo();

    cout << "\n---------- 程序结束，析构函数执行顺序 ----------\n";
    return 0;
}
