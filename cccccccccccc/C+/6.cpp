#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;   // 字符指针，动态适配长度
    int len;     // 字符串长度
public:
    // 1. 构造函数：支持字符串常量初始化
    String(const char* s = "");
    // 2. 拷贝构造函数：支持对象间复制
    String(const String& other);
    // 析构函数：释放堆内存
    ~String();

    // 获取字符串长度（匹配测试用例的Length()）
    int Length() const;

    // 3. 赋值重载：字符串常量赋值
    String& operator=(const char* s);
    // 3. 赋值重载：对象间赋值
    String& operator=(const String& other);

    // 4. 字符串连接 +
    String operator+(const String& other) const;
    // 4. 字符串连接 +=
    String& operator+=(const String& other);

    // 5. 下标运算符重载（可读写字符）
    char& operator[](int index);

    // 6. 比较运算符 ==
    bool operator==(const String& other) const;
    // 6. 比较运算符 <
    bool operator<(const String& other) const;

    // 7. 友元：输出运算符 <<
    friend ostream& operator<<(ostream& os, const String& s);
    // 7. 友元：输入运算符 >>
    friend istream& operator>>(istream& is, String& s);
};

// ===== 成员函数实现 =====
// 构造函数
String::String(const char* s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
}

// 拷贝构造（深拷贝，避免浅拷贝内存错误）
String::String(const String& other) {
    len = other.len;
    str = new char[len + 1];
    strcpy(str, other.str);
}

// 析构函数
String::~String() {
    delete[] str;
}

// 获取长度
int String::Length() const {
    return len;
}

// 字符串常量赋值
String& String::operator=(const char* s) {
    if (str == s) return *this; // 自赋值保护
    delete[] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

// 对象赋值
String& String::operator=(const String& other) {
    if (this == &other) return *this; // 自赋值保护
    delete[] str;
    len = other.len;
    str = new char[len + 1];
    strcpy(str, other.str);
    return *this;
}
// 字符串拼接 +
String String::operator+(const String& other) const {
    char* temp = new char[len + other.len + 1];
    strcpy(temp, str);
    strcat(temp, other.str);
    String res(temp);
    delete[] temp;
    return res;
}
// 字符串追加 +=
String& String::operator+=(const String& other) {
    char* temp = new char[len + other.len + 1];
    strcpy(temp, str);
    strcat(temp, other.str);
    delete[] str;
    str = temp;
    len += other.len;
    return *this;
}
// 下标访问（返回引用，支持 s[0] = 'x' 修改）
char& String::operator[](int index) {
    return str[index];
}
// 相等比较
bool String::operator==(const String& other) const {
    return strcmp(str, other.str) == 0;
}
// 小于比较（字典序）
bool String::operator<(const String& other) const {
    return strcmp(str, other.str) < 0;
}
// 输出重载
ostream& operator<<(ostream& os, const String& s) {
    os << s.str;
    return os;
}
// 输入重载
istream& operator>>(istream& is, String& s) {
    char buf[1024];
    is >> buf;
    s = buf; // 调用字符串赋值运算符
    return is;
}
// ===== 题目指定的测试主函数 =====
int main()
{
    String s1("Help!"),s2("Good!"),s3(s2),s4,s5;
    cout<<"s1="<<s1<<endl;
    s3="Hello!";
    cout<<"s3="<<s3<<endl;
    s3=s2;
    cout<<"s3="<<s3<<endl;
    s3+=s2;
    cout<<"s3="<<s3<<endl;
    cin>>s4;
    cout<<"s4="<<s4<<endl;
    s5=s3+s4;
    cout<<"s5="<<s5<<endl;
    s5[0]='g';
    cout<<"s5="<<s5<<endl;
    cout<<"strlen(s5)="<<s5.Length()<<endl;
    cout<<boolalpha<<(s3==s1)<<endl;
    cout<<boolalpha<<(s3<s1)<<endl;
    return 0;
}
