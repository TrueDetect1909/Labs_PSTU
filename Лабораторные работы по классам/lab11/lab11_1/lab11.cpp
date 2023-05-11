#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// Создание последовательного контейнера
deque<double> myDeque;

// Заполнение контейнера элементами типа double
void fillDeque() {
    myDeque.push_back(1.2);
    myDeque.push_back(3.4);
    myDeque.push_back(5.6);
    myDeque.push_back(7.8);
    myDeque.push_back(9.0);
}

// Добавление элемента с заданным ключом на заданную позицию контейнера
void addElement(double key, double value, int position) {
    deque<double>::iterator it = find(myDeque.begin(), myDeque.end(), key);
    if (it != myDeque.end()) {
        myDeque.insert(it + position, value);
    }
}

// Удаление элемента с заданным ключом из контейнера
void removeElement(double key) {
    deque<double>::iterator it = find(myDeque.begin(), myDeque.end(), key);
    if (it != myDeque.end()) {
        myDeque.erase(it);
    }
}

// Нахождение разницы между максимальным и минимальным элементами контейнера и вычитание ее из каждого элемента контейнера
void subtractMinMax() {
    double min = *min_element(myDeque.begin(), myDeque.end());
    double max = *max_element(myDeque.begin(), myDeque.end());
    double diff = max - min;
    for (deque<double>::iterator it = myDeque.begin(); it != myDeque.end(); ++it) {
        *it -= diff;
    }
}

// Вывод элементов контейнера
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
