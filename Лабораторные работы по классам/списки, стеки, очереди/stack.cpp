#include <iostream>
#include <string.h>
#define N 6
using namespace std;
struct Brothers
{
    string name;
    int age;
    bool married;
};
struct Stack
{
    Brothers array[N];
    int arrayElementsCount = 0;
    void push(Brothers Brothers)
    {
        if (size() >= N)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            array[arrayElementsCount] = Brothers;
            arrayElementsCount++;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            array[arrayElementsCount - 1] = {};
            arrayElementsCount--;
        }
    }
    bool isEmpty()
    {
        if (arrayElementsCount == 0)
            return true;
        else
            return false;
    }
    int size()
    {
        return arrayElementsCount;
    }
    void clear()
    {
        for (int i = size() - 1; i >= 0; i--)
        {
            array[i] = {};
        }
        arrayElementsCount = 0;
    }
    Brothers top()
    {
        if (!isEmpty())
        {
            return array[arrayElementsCount - 1];
        }
        else
        {
            cout << "Stack is empty." << endl;
            return {"Null element", 0, false};
        } }};
void print(Stack stack)
{
    Stack stackCopy = stack;
    Brothers group;
    for (int i = 0; i < stack.size(); i++)
    {
        group = stackCopy.top();
        if (group.married)
        {
            cout << "Married: name = " << group.name << " , age is " << group.age << endl;
        }
        else
            cout << "Not married: name = " << group.name << " , age is " << group.age << endl;
        stackCopy.pop();
    }}
int main()
{
    Stack stack;
    Brothers group;
    stack.push({"Oleg", 39, true});
    stack.push({"Igor", 83, true});
    stack.push({"Valeriy", 9, false});
    stack.push({"Arkadiy", 14, false});
    print(stack);
    cout << endl;
    group = stack.top();
    stack.pop();
    group.married = true;
    stack.push(group);
    print(stack);
    cout << endl;
    stack.push({"Vitaly", 93, false});
    stack.push({"Stas", 452, true});
    stack.push({"Maxim", 8, false});
    print(stack);
    cout << endl;
    stack.pop();
    print(stack);
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        stack.pop();
    }
    print(stack);
    system("pause");
    return 0;
}