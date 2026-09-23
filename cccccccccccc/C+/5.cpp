#include <iostream>
#include <cstring>
using namespace std;
class Staff
{
protected:
    char name[20];
    char gender[6];
    char birth[20];
    char phone[20];
public:
    Staff(const char* n, const char* g, const char* b, const char* p)
    {
        strcpy(name, n);
        strcpy(gender, g);
        strcpy(birth, b);
        strcpy(phone, p);
        cout << "【调用】虚基类Staff构造函数" << endl;
    }
    virtual ~Staff()
    {
        cout << "【调用】虚基类Staff析构函数" << endl;
    }
    void showStaffInfo() const
    {
        cout << "姓名：" << name << " 性别：" << gender << endl;
        cout << "出生日期：" << birth << " 电话：" << phone << endl;
    }
};
class Teacher : virtual public Staff
{
protected:
    char title[20];
public:
    Teacher(const char* n, const char* g, const char* b, const char* p, const char* t)
        : Staff(n, g, b, p)
    {
        strcpy(title, t);
        cout << "【调用】Teacher教师类构造函数" << endl;
    }
    ~Teacher()
    {
        cout << "【调用】Teacher教师类析构函数" << endl;
    }
    void showTeacherInfo() const
    {
        cout << "职称：" << title << endl;
    }
};
class Leader : virtual public Staff
{
protected:
    char duty[20];
public:
    Leader(const char* n, const char* g, const char* b, const char* p, const char* d)
        : Staff(n, g, b, p)
    {
        strcpy(duty, d);
        cout << "【调用】Leader干部类构造函数" << endl;
    }
    ~Leader()
    {
        cout << "【调用】Leader干部类析构函数" << endl;
    }
    void showLeaderInfo() const
    {
        cout << "职务：" << duty << endl;
    }
};
class DBTeacher : public Teacher, public Leader
{
private:
    double salary;
public:
    DBTeacher(const char* n, const char* g, const char* b, const char* p,
              const char* t, const char* d, double s)
        : Staff(n, g, b, p), Teacher(n, g, b, p, t), Leader(n, g, b, p, d), salary(s)
    {
        cout << "【调用】DBTeacher双职教师构造函数" << endl;
    }
    ~DBTeacher()
    {
        cout << "【调用】DBTeacher双职教师析构函数" << endl;
    }
    void showAllInfo() const
    {
        cout << "===== 双职教师完整信息 =====" << endl;
        showStaffInfo();
        showTeacherInfo();
        showLeaderInfo();
        cout << "工资：" << salary << " 元" << endl << endl;
    }
};
int main()
{
    DBTeacher db("张三", "男", "1990-01-01", "13800138000", "副教授", "教研室主任", 8500.0);
    db.showAllInfo();
    Leader ss("李四","男","1999-12-13","15253530892","后勤主任");
    ss.showStaffInfo();
    ss.showLeaderInfo();
    return 0;
}
