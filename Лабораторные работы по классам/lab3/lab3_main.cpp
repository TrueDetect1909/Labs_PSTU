#include "Time.h"
#include <iostream>
using namespace std;
// перегрузка операции присваивания
Time &Time::operator=(const Time &t)
{
    // проверка на самоприсваивание
    if (&t == this)
        return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}
// перегрузка префиксной операции инкремент
Time &Time::operator++()
{
    int temp = min * 60 + sec;
    temp++;
    min = temp / 60;
    sec = temp % 60;
    return *this;
}
// перегрузка постфиксной операции инкремент
Time Time::operator++(int)
{
    int temp = min * 60 + sec;
    temp++;
    Time t(min, sec);
    min = temp / 60;
    sec = temp % 60;
    return t;
}
// перегрузка бинарной операции сложения
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
// перегрузка глобальной функции-операции ввода
istream &operator>>(istream &in, Time &t)
{
    cout << "min?";
    in >> t.min;
    cout << "sec?";
    in >> t.sec;
    return in;
}
// перегрузка глобальной функции-операции вывода
ostream &operator<<(ostream &out, const Time &t)
{

    return (out << t.min << " : " << t.sec);
}
int main()
{
    Time a;                    // конструктор без параметров
    Time b;                    // конструктор без параметров
    Time c;
    Time timer;                    // конструктор без параметров
    cin >> a;                  // ввод переменной
    cin >> b;                  // ввод переменной
    cin >> timer;                       // префиксная операция инкремент
    a = a + timer;
    b = b - timer;         // вывод переменной
    c = a + b;             // сложение и постфиксная операция инкремент
    cout << "a=" << a << endl; // вывод переменной
    cout << "b=" << b << endl; // вывод переменной
    cout << "c=" << c << endl; // вывод переменной
    system("pause");
    return 0;
}
