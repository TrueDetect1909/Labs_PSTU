#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int number, x;
int minimum = 1;
int maximum = 100;
int count = 0;
bool f = false;

int main() {
    setlocale(LC_ALL, "");
    
    srand(time(NULL));
    number = minimum + rand() % (maximum - minimum + 1);

    cout << "� ������� ����� �� 1 �� 100. �������� �������!" << endl;

    while (count!=7 && f==false) {
        count++;
        cout << "������� ���� �������: ";
        cin >> x;

        if (x>number) cout << "���� ����� ������, ��� ����������. ���������� ���������� �������: " << 7-count << endl << endl;
        else if (x<number) cout << "���� ����� ������, ��� ����������. ���������� ���������� �������: " << 7-count << endl << endl;
        else f = true;

    }
    if (f==true) cout << "�� ������� �����. ���������� ������������� �������: " << count << endl << endl;
    else cout << "���� ������� ���������. �� �� ������ ������� �����. ���������� ����� = " << number << endl << endl;

    system("pause");
    return 0;
}