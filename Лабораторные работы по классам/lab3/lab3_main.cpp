#include "Time.h"
#include <iostream>
using namespace std;
Time &Time::operator=(const Time &t)
{
    if (&t == this)
        return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}   
Time &Time::operator++()
{
    int temp = min * 60 + sec;
    temp++;
    min = temp / 60;
    sec = temp % 60;
    return *this;
}
    
Time Time::operator++(int)
{
    int temp = min * 60 + sec;
    temp++;
    Time t(min, sec);
    min = temp / 60;
    sec = temp % 60;
    return t;
}
Time Time::operator+(const Time &t)
{
    int temp1 = min * 60 + sec;
    int temp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (temp1 + temp2) / 60;
    p.sec = (temp1 + temp2) % 60;
    return p;
}
Time Time::operator-(const Time &t)
{
    int temp1 = min * 60 + sec;
    int temp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (temp1 - temp2) / 60;
    p.sec = (temp1 - temp2) % 60;
    return p;
}

istream &operator>>(istream &in, Time &t)
{
    cout << "min?";
    in >> t.min;
    cout << "sec?";
    in >> t.sec;
    return in;
}
ostream &operator<<(ostream &out, const Time &t)
{

    return (out << t.min << " : " << t.sec);
}
int main()
{
    Time a;                       
    Time b;                       
    Time c;
    Time timer;                       
    cin >> a;                    
    cin >> b;                    
    cin >> timer;                          
    a = a + timer;
    b = b - timer;           
    c = a + b;                  
    cout << "a=" << a << endl;   
    cout << "b=" << b << endl;   
    cout << "c=" << c << endl;   
    system("pause");
    return 0;
}
