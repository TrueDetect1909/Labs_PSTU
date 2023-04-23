#include <iostream>
#include <vector>

struct Data {
    int value;
};

class Queue {
public:
    void enqueue(const Data& data) {
        queue.push_back(data);
    }

    void dequeue() {
        if (!queue.empty()) {
            queue.erase(queue.begin());
        }
    }

    void insertAt(int index, const Data& data) {
        if (index >= 0 && index <= queue.size()) {
            queue.insert(queue.begin() + index, data);
        }
    }

    void removeAt(int index) {
        if (index >= 0 && index < queue.size()) {
            queue.erase(queue.begin() + index);
        }
    }

    void display() {
        for (const auto& data : queue) {
            std::cout << data.value << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<Data> queue;
};

int main() {
    Queue q;
    int choice, index;
    Data data;

    while (true) {
        std::cout << "1. Enqueue\n2. Dequeue\n3. Insert at index\n4. Remove at index\n5. Display\n6. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value: ";
                std::cin >> data.value;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                std::cout << "Enter index: ";
                std::cin >> index;
                std::cout << "Enter value: ";
                std::cin >> data.value;
                q.insertAt(index, data);
                break;
            case 4:
                std::cout << "Enter index: ";
                std::cin >> index;
                q.removeAt(index);
                break;
            case 5:
                q.display();
                break;
            case 6:
                return 0;
            default:
                std::cout << "Invalid choice\n";
        }
    }

    return 0;
}