#include <iostream>

using namespace std;

int i=1;
int result;

int main () {
    setlocale(LC_ALL, "");
    result = ++i*i++;

    cout << "Значение выражения ++i*i++ равно " << result << endl;
    cout << "Значение i в данный момент равно " << i << endl;

    system("pause");
    return 0;
}