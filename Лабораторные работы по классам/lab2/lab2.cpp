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

void print_marsrut(marsrut t)
{
    t.show();
}
int main()
{

    marsrut t1;
    t1.show();

    marsrut t2("Computer", "sfhfgh", 15000);
    t2.show();

    marsrut t3 = t2;
    t3.set_firstplace("Telephon");
    t3.set_secondplace("fghfghj");
    t3.set_rasstoyanie(5000.0);

    print_marsrut(t3);

    t1 = make_marsrut();
    t1.show();
    return 0;
}
