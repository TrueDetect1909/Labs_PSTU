#include <iostream>

using namespace std;

int i=1;
int result;

int main () {
    setlocale(LC_ALL, "");
    result = ++i*i++;

    cout << "�������� ��������� ++i*i++ ����� " << result << endl;
    cout << "�������� i � ������ ������ ����� " << i << endl;

    system("pause");
    return 0;
}