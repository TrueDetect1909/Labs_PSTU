#include <iostream>
#include <windows.h>

using namespace std;

string vvod;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    do
    {
        cout << "Введите 5 символов: ";
        cin >> vvod;
    } 
    while (vvod.size()!=5);

    cout << "Измененное слово: " << vvod[4] << vvod[3] << vvod[2] << vvod[1] << vvod[0] << endl;

    system("pause");
    return 0;
}