#include <iostream>

using namespace std;

string vvod;

int main() {
    setlocale(LC_ALL, "");
    
    do
    {
        cout << "Введите 5 символов: ";
        cin >> vvod;
    } 
    while (vvod.size()!=5);

    cout << vvod[4] << vvod[3] << vvod[2] << vvod[1] << vvod[0] << endl;

    system("pause");
    return 0;
}