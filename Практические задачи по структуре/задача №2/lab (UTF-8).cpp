#include <iostream>

using namespace std;

const float GALLON = 7.481;
float vvod;
float result;

int main () {
    setlocale(LC_ALL, "");

    cout << "Введите количество галлонов для перевода в кубические футы: ";
    cin >> vvod;

    result = vvod / GALLON;

    cout << "Количество футов равно: " << result << endl;

    system("pause");
    return 0;
}