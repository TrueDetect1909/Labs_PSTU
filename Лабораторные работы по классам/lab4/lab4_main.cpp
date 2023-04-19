#include <iostream>
#include <cmath>
#include "Car.h"
#include "Lorry.h"
using namespace std;

dvestorony::dvestorony(void)
{
    naming = "";
    dlina = 0;
    shirina = 0;
}
// деструктор
dvestorony::~dvestorony(void)
{
}
// конструктор с параметрами
dvestorony::dvestorony(string M, int C, int P)
{
    naming = M;
    dlina = C;
    shirina = P;
}
// конструктор копирования
dvestorony::dvestorony(const dvestorony &dvestorony)
{
    naming = dvestorony.naming;
    dlina = dvestorony.dlina;
    shirina = dvestorony.shirina;
}
// модификаторы
void dvestorony::Set_dlina(int C)
{
    dlina = C;
}
void dvestorony::Set_naming(string M)
{
    naming = M;
}

void dvestorony::Set_shirina(int P)
{
    shirina = P;
}
// перегрузка операции присваивания
dvestorony &dvestorony::operator=(const dvestorony &c)
{
    if (&c == this)
        return *this;
    naming = c.naming;
    shirina = c.shirina;
    dlina = c.dlina;
    return *this;
}
// глобальная функция для ввода
istream &operator>>(istream &in, dvestorony &c)
{
    cout << "\nnaming:";
    in >> c.naming;
    cout << "\nshirina:";
    in >> c.shirina;
    cout << "\ndlina:";
    in >> c.dlina;
    return in;
}
// глобальная функция для вывода
ostream &operator<<(ostream &out, const dvestorony &c)
{
    out << "\nnaming : " << c.naming;
    out << "\ndlina : " << c.dlina;
    out << "\nshirina : " << c.shirina;
    out << "\n";
    return out;
}
gipotenuza::gipotenuza(void) : dvestorony()
{
    gruz = 0;
}
// дестрктор
gipotenuza::~gipotenuza(void)
{
}
// конструктор с параметрами
gipotenuza::gipotenuza(string M, int C, int P, double G) : dvestorony(M, C, P)
{
    gruz = G;
}
// конструктор копирования
gipotenuza::gipotenuza(const gipotenuza &L)
{
    naming = L.naming;
    dlina = L.dlina;
    shirina = L.shirina;
    gruz = L.gruz;
}
// модификатор
void gipotenuza::Set_Gruz(double G)
{
    gruz = G;
}
void gipotenuza::Gipotenuza(int K, int L)
{
    gruz = sqrt(K*K+L*L);
}
// оперция присваивания
gipotenuza &gipotenuza::operator=(const gipotenuza &l)
{
    if (&l == this)
        return *this;
    naming = l.naming;
    shirina = l.shirina;
    dlina = l.dlina;
    gruz = l.gruz;
    return *this;
}
// операция ввода
istream &operator>>(istream &in, gipotenuza &l)
{
    cout << "\nnaming:";
    in >> l.naming;
    cout << "\nshirina:";
    in >> l.shirina;
    cout << "\ndlina:";
    in >> l.dlina;
    return in;
}
// операция вывода
ostream &operator<<(ostream &out, const gipotenuza &l)
{
    out << "\nnaming : " << l.naming;
    out << "\ndlina : " << l.dlina;
    out << "\nshirina : " << l.shirina;
    out << "\nGRUZ : " << l.gruz;
    out << "\n";
    return out;
}

void f1(gipotenuza &c)
{
    int first = c.dlina;
    int second = c.shirina;
    c.Gipotenuza(first, second);

}
int main()
{
    // работа с классом dvestorony 
    dvestorony a;
    cin >> a;
    cout << a;
    dvestorony b("Ford", 4, 115);
    cout << b;
    a = b;
    cout << a;
    // работа с классом gipotenuza 
    gipotenuza c;
    cin >> c;
    f1(c);
    cout << c;
    // принцип подстановки 
    //передаем объект класса gipotenuza
    system("pause");
    return 0;
}
