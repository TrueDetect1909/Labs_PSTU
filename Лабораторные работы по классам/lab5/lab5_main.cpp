#include <iostream>
#include <vector>
#include <cmath>
#include "pair.h"
#include "rightAngled.h"
int main()
{
    Pair pair(2, 3);
    std::cout << "Product: " << pair.product() << std::endl;
    RightAngled rightangled(3, 4);
    rightangled.calculate_hypotenuse();
    std::cout << "Hypotenuse: " << rightangled.get_hypotenuse() << std::endl;
    system("pause");
    return 0;
}