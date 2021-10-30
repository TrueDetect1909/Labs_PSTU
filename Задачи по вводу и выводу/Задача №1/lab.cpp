#include <iostream>

using namespace std;

float a, b, result;

int main() {
    setlocale(LC_ALL, "");

    cout << "Введите первое число: ";
    cin >> a;

    cout << "Введите второе число: ";
    cin >> b;    
    
    result = a*b;

    cout << "Ответ равен: " << result << endl;

    system("pause");
    return 0;
}