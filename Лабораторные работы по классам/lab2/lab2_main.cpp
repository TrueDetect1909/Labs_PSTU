#include "marsrut.h"
#include <iostream>
#include <string>
using namespace std;

marsrut make_marsrut()
{
    string s;
    string i;
    float d;
    cout << "Vvedite 1: ";
    cin >> s;
    cout << "Vvedite 2: ";
    cin >> i;
    cout << "Vvedite rasstoianie: ";
    cin >> d;
    marsrut t(s, i, d);
    return t;
}
// функци€ дл€ передачи объекта как параметра
void print_marsrut(marsrut t)
{
    t.show();
}
int main()
{
    // конструктор без параметров
    marsrut t1;
    t1.show();
    // коструктор с параметрами
    marsrut t2("Computer", "sfhfgh", 15000);
    t2.show();
    // конструктор копировани€
    marsrut t3 = t2;
    t3.set_firstplace("Telephon");
    t3.set_secondplace("fghfghj");
    t3.set_rasstoyanie(5000.0);
    // конструктор копировани€
    print_marsrut(t3);
    // конструктор копировани€
    t1 = make_marsrut();
    t1.show();
    return 0;
}
