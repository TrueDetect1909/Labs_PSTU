#pragma once
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// пользовательский тип
struct MyType {
    int key;
    string value;

    // перегрузка оператора <
    bool operator<(const MyType& other) const {
        return key < other.key;
    }

    // перегрузка оператора ==
    bool operator==(const MyType& other) const {
        return key == other.key && value == other.value;
    }
};

// глобальная функция для добавления элемента с заданным ключом на заданную позицию
void addElement(queue<MyType>& q, MyType element, int position) {
    queue<MyType> tempQ;
    int size = q.size();
    for (int i = 0; i < size; i++) {
        if (i == position) {
            tempQ.push(element);
        }
        tempQ.push(q.front());
        q.pop();
    }
    q = tempQ;
}

// глобальная функция для удаления элемента с заданным ключом
void removeElement(queue<MyType>& q, MyType element) {
    queue<MyType> tempQ;
    int size = q.size();
    for (int i = 0; i < size; i++) {
        if (q.front() == element) {
            q.pop();
            break;
        }
        tempQ.push(q.front());
        q.pop();
    }
    while (!q.empty()) {
        tempQ.push(q.front());
        q.pop();
    }
    q = tempQ;
}

// глобальная функция для вычисления разницы между максимальным и минимальным элементами и вычитания ее из каждого элемента
void subtractMaxMin(queue<MyType>& q) {
    int maxKey = q.front().key;
    int minKey = q.front().key;
    int size = q.size();
    for (int i = 0; i < size; i++) {
        maxKey = max(maxKey, q.front().key);
        minKey = min(minKey, q.front().key);
        q.push(q.front());
        q.pop();
    }
    int diff = maxKey - minKey;
    for (int i = 0; i < size; i++) {
        MyType temp = q.front();
        temp.key -= diff;
        q.pop();
        q.push(temp);
    }
}