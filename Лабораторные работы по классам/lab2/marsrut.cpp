#include "marsrut.h"
#include <iostream>
#include <string>
marsrut::marsrut()
{
    firstplace = "";
    secondplace = "";
    rasstoyanie = 0;
    cout << "Constructor bez parametrov dlia objecta" << this << endl;
}
// конструктор с параметрами
marsrut::marsrut(string N, string K, float S)
{
    firstplace = N;
    secondplace = K;
    rasstoyanie = S;
    cout << "Constructor s parametrami dlia objecta" << this << endl;
}
// конструктор копирования
marsrut::marsrut(const marsrut &t)
{
    firstplace = t.firstplace;
    secondplace = t.secondplace;
    rasstoyanie = t.rasstoyanie;

    cout << "Constructor copirovania dlia objecta" << this << endl;
}
// деструктор
marsrut::~marsrut()
{
    cout << "Destructor dlia objecta" << this << endl;
}
// селекторы
string marsrut::get_firstplace()
{
    return firstplace;
}
string marsrut::get_secondplace()
{
    return secondplace;
}
float marsrut::get_rasstoyanie()
{
    return rasstoyanie;
}
// модификаторы
void marsrut::set_firstplace(string N)
{
    firstplace = N;
}
void marsrut::set_secondplace(string K)
{
    secondplace = K;
}
void marsrut::set_rasstoyanie(float S)
{
    rasstoyanie = S;
}
// метод для просмотра атрибутов
void marsrut::show()
{
    cout << "firstplace :" << firstplace << endl;
    cout << "secondplace :" << secondplace << endl;
    cout << "rasstoyanie :" << rasstoyanie << endl;
}