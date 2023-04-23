#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    char data;
    Node *next;
};

class firstLinkedList {
private:
    Node *head;
    Node *tail;

public:
    firstLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addNode(char n) {
        Node *temp = new Node();
        temp->data = n;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void insertMultipleAfter(char after, const vector<char> &values) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data == after) {
                Node *prev = temp;
                for (char value : values) {
                    Node *newNode = new Node();
                    newNode->data = value;
                    newNode->next = prev->next;
                    prev->next = newNode;
                    prev = newNode;
                    if (prev->next == NULL) {
                        tail = prev;
                    }
                }
                break;
            }
            temp = temp->next;
        }
    }

    void deleteNode(char value) {
        if (head == NULL) return;

        if (head->data == value) {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *prev = head;
        Node *current = head->next;
        while (current != NULL) {
            if (current->data == value) {
                prev->next = current->next;
                if (current->next == NULL) {
                    tail = prev;
                }
                delete current;
                break;
            }
            prev = current;
            current = current->next;
        }
    }

    void printList() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    firstLinkedList list;
    list.addNode('a');
    list.addNode('b');
    list.addNode('c');
    list.printList(); // выведет: a b c

    list.insertMultipleAfter('b', {'x', 'y', 'z'});
    list.printList(); // выведет: a b x y z c

    list.deleteNode('x');
    list.printList(); // выведет: a b y z c
    system("pause");
    return 0;
}