#include "lab.h"

int main() {
    Vector<int> vec;
    vec.fill(5);
    vec.print();
    vec.add(3, 2);
    vec.print();
    vec.remove(4);
    vec.print();
    vec.subtract();
    vec.print();
    return 0;
}
