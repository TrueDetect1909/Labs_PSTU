#include <iostream>

using namespace std;

float fahrenheit;
float celsius;

int perevod(float x) {
    float a = 5.0 / 9.0;
    float b = fahrenheit - 32.0;
    float c = a * b;

    return c;
}

int main () {
    setlocale(LC_ALL, "");

    cout << "������� ���������� �������� �� ����������: ";
    cin >> fahrenheit;
    
    celsius = perevod(fahrenheit);

    cout << "���������� �������� �� ������� �����: " << celsius << endl;

    system("pause");
    return 0;
}