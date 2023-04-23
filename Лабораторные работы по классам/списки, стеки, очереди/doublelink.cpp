#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void addNode(char n)
    {
        Node *temp = new Node();
        temp->data = n;
        temp->next = NULL;
        if (head == NULL)
        {
            temp->prev = NULL;
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void addNodesAfter(char target, const string &nodes)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
            {
                for (char node : nodes)
                {
                    Node *newNode = new Node();
                    newNode->data = node;
                    newNode->next = temp->next;
                    newNode->prev = temp;
                    if (temp->next != NULL)
                        temp->next->prev = newNode;
                    else
                        tail = newNode;
                    temp->next = newNode;
                    temp = newNode;
                }
                break;
            }
            temp = temp->next;
        }
    }

    void removeNode(char n)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == n)
            {
                if (temp == head && temp == tail)
                {
                    head = NULL;
                    tail = NULL;
                }
                else if (temp == head)
                {
                    head = temp->next;
                    head->prev = NULL;
                }
                else if (temp == tail)
                {
                    tail = temp->prev;
                    tail->next = NULL;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    list.addNode('a');
    list.addNode('b');
    list.addNode('c');
    list.printList(); // выведет: a b c
    list.removeNode('b');
    list.printList(); // выведет: a c
    list.addNodesAfter('a', "xy");
    list.printList(); // выведет: a x y c
    system("pause");
    return 0;
}