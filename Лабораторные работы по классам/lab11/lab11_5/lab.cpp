#include <iostream>
#include "Header.h"
int main() {
    Vector<int> vec;
    vec.fill({ 1, 2, 3, 4, 5 });
    vec.add(6, 2);
    vec.remove(4);
    vec.subtractMinMax();
    vec.print();
    return 0;
}
