#include <iostream>
#include <queue>
#include <algorithm>

template <typename T>
class Vector {
private:
    std::queue<T> container;
public:
    Vector() {}

    void fill(const std::initializer_list<T>& list) {
        for (const auto& item : list) {
            container.push(item);
        }
    }

    void add(const T& item, int position) {
        std::queue<T> temp;
        int size = container.size();
        for (int i = 0; i < size; i++) {
            if (i == position) {
                temp.push(item);
            }
            temp.push(container.front());
            container.pop();
        }
        container = temp;
    }

    void remove(const T& item) {
        std::queue<T> temp;
        int size = container.size();
        for (int i = 0; i < size; i++) {
            if (container.front() != item) {
                temp.push(container.front());
            }
            container.pop();
        }
        container = temp;
    }

    void subtractMinMax() {
        T min = container.front();
        T max = container.front();
        int size = container.size();
        for (int i = 0; i < size; i++) {
            T item = container.front();
            if (item < min) {
                min = item;
            }
            if (item > max) {
                max = item;
            }
            container.pop();
            container.push(item);
        }
        T diff = max - min;
        for (int i = 0; i < size; i++) {
            T item = container.front();
            container.pop();
            container.push(item - diff);
        }
    }

    void print() {
        int size = container.size();
        for (int i = 0; i < size; i++) {
            std::cout << container.front() << " ";
            container.pop();
        }
        std::cout << std::endl;
    }
};