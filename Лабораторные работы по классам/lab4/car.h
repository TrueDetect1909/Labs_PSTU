#pragma once 
#include <string> 
#include <iostream> 
using namespace std; 
class dvestorony
{
    // конструктор без параметров 
    public:
    dvestorony(void);

public:
    // деструктор
    virtual ~dvestorony(void);
    // констрктор с параметрами 
    dvestorony(string,int,int);
    // конструктор копирования 
    dvestorony(const dvestorony&);

    // селекторы
    string Get_naming() { return naming; }
    int Get_dlina() { return dlina; }
    int Get_shirina() { return shirina; }
    // модификаторы
    void Set_naming(string);
    void Set_dlina(int);
    void Set_shirina(int);
    // перегрузка операции присваивания 
    dvestorony& operator=(const dvestorony&);
    // глобальные операторы-функции ввода-вывода
    friend istream &operator>>(istream &in, dvestorony &c);
    friend ostream &operator<<(ostream &out, const dvestorony &c);
    // атрибуты protected:
    string naming;
    int dlina;
    int shirina;
};
