#include <cmath>
#include "pair.h"
class RightAngled : public Pair
{
private:
    int hypotenuse;

public:
    RightAngled(int f, int s) : Pair(f, s) {}
    void calculate_hypotenuse()
    {
        hypotenuse = sqrt(first * first + second * second);
    }
    int get_hypotenuse() const
    {
        return hypotenuse;
    }
};