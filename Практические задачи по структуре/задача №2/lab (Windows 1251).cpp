#include <iostream>

using namespace std;

const float GALLON = 7.481;
float vvod;
float result;

int main () {
    setlocale(LC_ALL, "");

    cout << "������� ���������� �������� ��� �������� � ���������� ����: ";
    cin >> vvod;

    result = vvod / GALLON;

    cout << "���������� ����� �����: " << result << endl;

    system("pause");
    return 0;
}