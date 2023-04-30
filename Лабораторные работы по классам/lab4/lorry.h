#pragma once 
#include "car.h"
class gipotenuza :
public
dvestorony
{
public:
    gipotenuza(void);                                                  
    public:
    ~gipotenuza(void);                                               
    gipotenuza(string,int,int,double);   
    gipotenuza(const gipotenuza & ); 
    int Get_gruz() { return gruz; }                             
    void Set_Gruz(double);
    void Gipotenuza(int,int);
    gipotenuza &operator=(const gipotenuza &);                           
    friend istream &operator>>(istream &in, gipotenuza &l);          
    friend ostream &operator<<(ostream &out, const gipotenuza &l);    
protected:
    int gruz;                                                   
};
