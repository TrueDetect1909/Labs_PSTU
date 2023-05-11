#include "Header.h"
#include <iostream>
using namespace std;
int main() {
    queue<MyType> q;

    // ���������� ������� ���������� ����������������� ����
    q.push({ 5, "five" });
    q.push({ 3, "three" });
    q.push({ 7, "seven" });
    q.push({ 1, "one" });
    q.push({ 9, "nine" });

    // ���������� �������� � �������� ������ �� �������� �������
    MyType newElement = { 4, "four" };
    int position = 2;
    addElement(q, newElement, position);

    // �������� �������� � �������� ������
    MyType elementToRemove = { 7, "seven" };
    removeElement(q, elementToRemove);

    // ���������� ������� ����� ������������ � ����������� ���������� � ��������� �� �� ������� ��������
    subtractMaxMin(q);

    // ����� ��������� �������
    while (!q.empty()) {
        cout << q.front().key << " " << q.front().value << endl;
        q.pop();
    }

    return 0;
}
