#include <iostream>

using namespace std;

float a, b, result;

int main() {
    setlocale(LC_ALL, "");

    cout << "������� ������ �����: ";
    cin >> a;

    cout << "������� ������ �����: ";
    cin >> b;    
    
    result = a*b;

    cout << "����� �����: " << result << endl;

    system("pause");
    return 0;
}