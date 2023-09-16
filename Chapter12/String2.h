#ifndef E9B30721_1585_4B3C_B0E7_38ABEA9A599D
#define E9B30721_1585_4B3C_B0E7_38ABEA9A599D
#include <iostream>
#include <cstring>
#include <cctype>

class String
{
private:
    char * str; // 字符串的地址
    int len;    // 字符串的长度
    static const int CINLIM = 80;   // cin允许输入的最大值

public:
    String();                       // 默认构造函数 -> Line 54
    String(const char *);           // 构造函数（使用字符串） -> Line 57
    String(const char, int n = 1);  // 构造函数（将字符复制n次） -> Line 65
    String(const String &);         // 拷贝构造函数 -> Line 75
    ~String();                      // 析构函数 -> Line 83

    int length() const {return len;}        // 字符串长度（原始接口）
    int size() const {return len;}          // 字符串长度（与其他容器类兼容的接口）
    char operator[](int i) {return str[i];} // 返回字符串的指定字符的引用

    String & operator=(const String &);     // 用另一对象为对象赋值 -> Line 91
    String & operator=(const char *);       // 用字符串为对象赋值 -> Line 103
    String & operator+=(const String &);    // 合并两个对象给前一对象 -> Line 115
    String & operator+=(const char *);      // 合并对象和字符串给对象 -> Line 127
    String & operator+=(const char);        // 合并对象和字符给对象 -> Line 139
    String operator+(const String &) const; // 合并两个对象 -> Line 150
    String operator+(const char *) const;   // 合并对象和字符串 -> Line 158
    String operator+(const char) const;     // 合并对象和字符 -> Line 166

    bool operator<(const String &) const;   // 判断两个对象大小，下同 -> Line 179
    bool operator>(const String &) const;
    bool operator==(const String &) const;
    bool operator<=(const String &) const;
    bool operator>=(const String &) const;
    bool operator!=(const String &) const;

    String & StringLow();   // 将字符转为小写
    String & StringUp();    // 将字符转为大写
    
    int has(char);  // 读取字符串中有多少指定字符

    friend String operator+(const char *, const String &);  // 友元：合并字符串和对象 -> Line 173
    friend String operator+(const char, const String &);    // 友元：合并字符和对象 -> Line 175

    friend std::ostream & operator<<(std::ostream &, const String &);   // 友元：输出 -> Line 216
    friend std::istream & operator>>(std::istream &, String &);         // 友元：输入 -> Line 220
};

/*默认构造函数 -> Line 15*/
String::String(): str(nullptr), len(0) {}

/*构造函数（使用字符串） -> Line 16*/
String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
}

/*构造函数（将字符复制n次） -> Line 17*/
String::String(const char ch, int n)
{
    str = new char[n + 1];
    len = n;
    for (int i = 0; i < n; ++i)
        str[i] = ch;
    str[n] = '\0';
}

/*拷贝构造函数 -> Line 18*/
String::String(const String & s)
{
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
}

/*析构函数 -> Line 19*/
String::~String()
{
    delete [] str;
    str = nullptr;
    len = 0;
}

/*用另一对象为对象赋值 -> Line 25*/
String & String::operator=(const String & s)
{
    char * temp = new char[len + s.len + 1];
    std::strcpy(temp, str);
    std::strcpy(temp + len, s.str);
    delete [] str;
    str = temp;
    len += s.len;
    return *this;
}

/*用字符串为对象赋值 -> Line 26*/
String & String::operator=(const char * s)
{
    char * temp = new char[len + std::strlen(s) + 1];
    std::strcpy(temp, str);
    std::strcpy(temp + len, s);
    delete[] str;
    str = temp;
    len += std::strlen(s);
    return *this;
}

/*合并两个对象给前一个对象 -> Line 27*/
String & String::operator+=(const String & s)
{
    char * temp = new char[len + s.len + 1];
    std::strcpy(temp, str);
    std::strcpy(temp + len, s.str);
    delete [] str;
    str = temp;
    len += s.len;
    return *this;
}

/*合并对象和字符串给对象 -> Line 28*/
String & String::operator+=(const char * s)
{
    char * temp = new char[len + std::strlen(s) + 1];
    std::strcpy(temp, str);
    std::strcpy(temp + len, s);
    delete[] str;
    str = temp;
    len += std::strlen(s);
    return *this;
}

/*合并对象和字符给对象 -> Line 29*/
String & String::operator+=(const char s)
{
    char * temp = new char[len + 2];
    std::strcpy(temp, str);
    temp[len++] = s;
    delete[] str;
    str = temp;
    return *this;
}

/*合并两个对象 -> Line 30*/
String String::operator+(const String & s) const
{
    String temp = *this;
    temp += s;
    return temp;
}

/*合并对象和字符串 -> Line 31*/
String String::operator+(const char * s) const
{
    String temp = *this;
    temp += s;
    return temp;
}

/*合并对象和字符 -> Line 32*/
String String::operator+(const char ch) const
{
    String temp = *this;
    temp += ch;
    return temp;
}

String operator+(const char * s1, const String & s2)
    {return s2 + s1;}   // 友元：合并字符串和对象 -> Line 46
String operator+(const char ch, const String & s)
    {return s + ch;}    // 友元：合并字符和对象 -> Line 47

/*判断两个对象的大小 -> Line 34*/
bool String::operator<(const String & s) const
    {return std::strcmp(str, s.str) < 0;}
bool String::operator>(const String & s) const
    {return std::strcmp(str, s.str) > 0;}
bool String::operator==(const String & s) const
    {return std::strcmp(str, s.str) == 0;}
bool String::operator<=(const String & s) const
    {return std::strcmp(str, s.str) <= 0;}
bool String::operator>=(const String & s) const
    {return std::strcmp(str, s.str) >= 0;}
bool String::operator!=(const String & s) const
    {return std::strcmp(str, s.str) != 0;}

String & String::StringLow()
{
    for (int i = 0; i < len; ++i)
        str[i] = std::tolower(str[i]);
    return *this;
}

String & String::StringUp()
{
    for (int i = 0; i < len; ++i)
        str[i] = std::toupper(str[i]);
    return *this;
}

int String::has(char ch)
{
    int ans = 0;
    for (int i = 0; i < len; ++i)
        if (str[i] == ch)
            ++ans;
    return ans;
}

/*友元：输出 -> Line 49*/
std::ostream & operator<<(std::ostream & os, const String & s)
    {return os << s.str;}

/*友元：输入 -> Line 50*/
std::istream & operator>>(std::istream & is, String & s)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        s = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

#endif /* E9B30721_1585_4B3C_B0E7_38ABEA9A599D */
