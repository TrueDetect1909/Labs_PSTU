#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// �������� ����������������� ����������
deque<double> myDeque;

// ���������� ���������� ���������� ���� double
void fillDeque() {
    myDeque.push_back(1.2);
    myDeque.push_back(3.4);
    myDeque.push_back(5.6);
    myDeque.push_back(7.8);
    myDeque.push_back(9.0);
}

// ���������� �������� � �������� ������ �� �������� ������� ����������
void addElement(double key, double value, int position) {
    deque<double>::iterator it = find(myDeque.begin(), myDeque.end(), key);
    if (it != myDeque.end()) {
        myDeque.insert(it + position, value);
    }
}

// �������� �������� � �������� ������ �� ����������
void removeElement(double key) {
    deque<double>::iterator it = find(myDeque.begin(), myDeque.end(), key);
    if (it != myDeque.end()) {
        myDeque.erase(it);
    }
}

// ���������� ������� ����� ������������ � ����������� ���������� ���������� � ��������� �� �� ������� �������� ����������
void subtractMinMax() {
    double min = *min_element(myDeque.begin(), myDeque.end());
    double max = *max_element(myDeque.begin(), myDeque.end());
    double diff = max - min;
    for (deque<double>::iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
        *it -= diff;
    }
}

// ����� ��������� ����������
void printDeque() {
    for (deque<double>::iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    fillDeque();
    printDeque();
    addElement(3.4, 2.2, 1);
    printDeque();
    removeElement(5.6);
    printDeque();
    subtractMinMax();
    printDeque();
    return 0;
}
