#include <iostream>
#include "fraction.h"
#include <cmath>
using namespace std;
fraction make_fraction(int F, int S)
{
    fraction t;   // создали временную переменную
    t.Init(F, S); // инициализировали пол€ переменной t с помощью параметров функции
    return t;     // вернули значение переменной t
}
int main()
{
    fraction A;
    fraction B;
    A.Init(5000, 2); // инициализаци€ переменной ј
    B.Read();       // ввод полей переменных ¬
    A.Show();       // вывод значений полей переменной ј
    B.Show();       // вывод значений полей переменной ¬
    // вывод значени€ степени, вычисленного с помощью функции Power()
    cout << "A.Cost(" << A.first << "," << A.second << ")=" << A.Cost() << endl;
    cout << "B.Cost(" << B.first << "," << B.second << ")=" << B.Cost() << endl;
    // указатели
    fraction *X = new fraction; // выделение пам€ти под динамическую переменную
    X->Init(200, 5);            // инициализаци€
    X->Show();                  // вывод значений полей
    X->Power();                 // вычисление степени

    cout << "X.Cost(" << X->first << "," << X->second << ")=" << X->Cost() << endl;
    // массивы
    fraction mas[3]; // определение массива
    for (int i = 0; i < 3; i++)
        mas[i].Read(); // чтение значений полей
    for (int i = 0; i < 3; i++)
        mas[i].Show(); // вывод значений полей
    for (int i = 0; i < 3; i++)
    {
        mas[i].Cost(); // вычисление степени
        cout << "mas[" << i << "].Cost(" << mas[i].first << "," << mas[i].second << ")=";
        cout << mas[i].Cost() << endl;
    }
    // динамические масивы
    fraction *p_mas = new fraction[3]; // выделение пам€ти
    for (int i = 0; i < 3; i++)
        p_mas[i].Read(); // чтение значений полей
    for (int i = 0; i < 3; i++)
        p_mas[i].Show(); // вывод значений полей

    for (int i = 0; i < 3; i++)
    {
        p_mas[i].Cost(); // вычисление степени
        cout << "p_mas[" << i << "].Cost(" << p_mas[i].first << "," << p_mas[i].second;
        cout << ")=" << p_mas[i].Cost() << endl;
    }
    // вызов функции make_fraction()
    double y;
    int z;
    cout << "first?";
    cin >> y;
    cout << "second?";
    cin >> z;
    // переменна€ F формируетс€ с помощью функции make_fraction()
    fraction F = make_fraction(y, z);
    F.Show();
    return 0;
}
