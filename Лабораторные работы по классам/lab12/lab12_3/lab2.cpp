#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

template<typename T>
class Vector {
private:
    std::queue<T> container;
public:
    void fillContainer(const std::map<T, int>& elements) {
        for (auto& element : elements) {
            for (int i = 0; i < element.second; ++i) {
                container.push(element.first);
            }
        }
    }

    void addElement(const T& key, int position) {
        std::queue<T> tempContainer;
        int currentPosition = 0;
        while (!container.empty()) {
            if (currentPosition == position) {
                tempContainer.push(key);
            }
            tempContainer.push(container.front());
            container.pop();
            ++currentPosition;
        }
        if (currentPosition == position) {
            tempContainer.push(key);
        }
        container = tempContainer;
    }

    void removeElement(const T& key) {
        std::queue<T> tempContainer;
        while (!container.empty()) {
            if (container.front() != key) {
                tempContainer.push(container.front());
            }
            container.pop();
        }
        container = tempContainer;
    }

    void subtractMinMax() {
        if (container.empty()) {
            return;
        }
        T minElement = container.front();
        T maxElement = container.front();
        std::queue<T> tempContainer;
        while (!container.empty()) {
            minElement = std::min(minElement, container.front());
            maxElement = std::max(maxElement, container.front());
            container.pop();
        }
        int difference = maxElement - minElement;
        while (!tempContainer.empty()) {
            tempContainer.pop();
        }
        while (!container.empty()) {
            tempContainer.push(container.front() - difference);
            container.pop();
        }
        container = tempContainer;
    }

    void printContainer() {
        std::queue<T> tempContainer = container;
        while (!tempContainer.empty()) {
            std::cout << tempContainer.front() << " ";
            tempContainer.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector<int> vector;
    std::map<int, int> elements = { {1, 2}, {2, 3}, {3, 1}, {4, 4} };
    vector.fillContainer(elements);
    vector.printContainer();
    vector.addElement(5, 3);
    vector.printContainer();
    vector.removeElement(2);
    vector.printContainer();
    vector.subtractMinMax();
    vector.printContainer();
    return 0;
}
