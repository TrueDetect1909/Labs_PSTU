#include <iostream>
#include <string>
using namespace std;
class marsrut
{
    // атрибуты
    string firstplace;
    string secondplace;
    float rasstoyanie;

public:
    marsrut();                       // конструктор без параметров
    marsrut(string, string, float);    // конструктор с параметрами
    marsrut(const marsrut &);          // конструктор копирования
    ~marsrut();                      // деструктор
    string get_firstplace();     // селектор
    void set_firstplace(string); // модификатор
    string get_secondplace();         // селектор
    void set_secondplace(string);     // модификатор
    float get_rasstoyanie();         // селектор
    void set_rasstoyanie(float);     // модификатор
    void show();                   // просмотр атрибутов
};
