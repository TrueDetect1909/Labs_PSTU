#include <iostream>
#include "fraction.h"
#include <cmath>
using namespace std;
fraction make_fraction(int F, int S)
{
    fraction t;   
    t.Init(F, S); 
    return t;     
}
int main()
{
    fraction A;
    fraction B;
    A.Init(5000, 2); 
    B.Read();       
    A.Show();       
    B.Show();       
    
    cout << "A.Cost(" << A.first << "," << A.second << ")=" << A.Cost() << endl;
    cout << "B.Cost(" << B.first << "," << B.second << ")=" << B.Cost() << endl;
    
    fraction* X = new fraction; 
    X->Init(200, 5);            
    X->Show();                  
    X->Power();                 

    cout << "X.Cost(" << X->first << "," << X->second << ")=" << X->Cost() << endl;
    
    fraction mas[3]; 
    for (int i = 0; i < 3; i++)
        mas[i].Read(); 
    for (int i = 0; i < 3; i++)
        mas[i].Show(); 
    for (int i = 0; i < 3; i++)
    {
        mas[i].Cost(); 
        cout << "mas[" << i << "].Cost(" << mas[i].first << "," << mas[i].second << ")=";
        cout << mas[i].Cost() << endl;
    }
    
    fraction* p_mas = new fraction[3]; 
    for (int i = 0; i < 3; i++)
        p_mas[i].Read(); 
    for (int i = 0; i < 3; i++)
        p_mas[i].Show(); 

    for (int i = 0; i < 3; i++)
    {
        p_mas[i].Cost(); 
        cout << "p_mas[" << i << "].Cost(" << p_mas[i].first << "," << p_mas[i].second;
        cout << ")=" << p_mas[i].Cost() << endl;
    }
    
    double y;
    int z;
    cout << "first?";
    cin >> y;
    cout << "second?";
    cin >> z;
    
    fraction F = make_fraction(y, z);
    F.Show();
    return 0;
}