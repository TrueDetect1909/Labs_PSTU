#include <iostream>
#include <cmath>
#include "fraction.h"
using namespace std;
void fraction::Init(int F, int S)
{
    first = F;
    second = S;
}

void fraction::Read()
{
    cout << "\nfirst?";
    cin >> first;
    cout << "\nsecond?";
    cin >> second;
}

void fraction::Show()
{
    cout << "\nfirst=" << first;
    cout << "\nsecond=" << second;
    cout << "\n";
}

double fraction::Power()
{
    return pow(first, second);
}
int fraction::Cost()
{
    return first * second;
}

