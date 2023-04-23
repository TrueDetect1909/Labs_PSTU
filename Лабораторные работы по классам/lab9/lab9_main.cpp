#include <iostream>
#include <vector>
#include "vector.h"

int main() {
    try {
        Vector v(3);
        v[0] = 1;
        v[1] = 2;
        v[2] = 3;
        std::cin >> A ;
        // добавляем элемент в конец
        v++;
        std::cin >> B ;
        // добавляем элемент в начало
        ++v;

        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }
    system("pause");
    return 0;
}
