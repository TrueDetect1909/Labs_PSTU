#pragma once 
#include "car.h"

// класс gipotenuza наследуется от класса dvestorony 
class gipotenuza :
public
dvestorony
{
public:
    gipotenuza(void);                                              // конструктор без параметров 
    public:
    ~gipotenuza(void);                                             // деструктор 
    gipotenuza(string,int,int,double);//конструктор с параметрами 
    gipotenuza(const gipotenuza & );//конструктор копирования
    int Get_gruz() { return gruz; }                           // модификатор 
    void Set_Gruz(double);//селектор
    void Gipotenuza(int,int);
    gipotenuza &operator=(const gipotenuza &);                         // операция присваивания
    friend istream &operator>>(istream &in, gipotenuza &l);        // операция ввода
    friend ostream &operator<<(ostream &out, const gipotenuza &l); // операция вывода 
    protected:
    int gruz;                                                 // атрибут грузоподъемность
};
