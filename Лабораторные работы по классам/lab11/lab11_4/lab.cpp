#include "Header.h"
#include <iostream>
using namespace std;
int main() {
    queue<MyType> q;

    // заполнение очереди элементами пользовательского типа
    q.push({ 5, "five" });
    q.push({ 3, "three" });
    q.push({ 7, "seven" });
    q.push({ 1, "one" });
    q.push({ 9, "nine" });

    // добавление элемента с заданным ключом на заданную позицию
    MyType newElement = { 4, "four" };
    int position = 2;
    addElement(q, newElement, position);

    // удаление элемента с заданным ключом
    MyType elementToRemove = { 7, "seven" };
    removeElement(q, elementToRemove);

    // вычисление разницы между максимальным и минимальным элементами и вычитание ее из каждого элемента
    subtractMaxMin(q);

    // вывод элементов очереди
    while (!q.empty()) {
        cout << q.front().key << " " << q.front().value << endl;
        q.pop();
    }

    return 0;
}
