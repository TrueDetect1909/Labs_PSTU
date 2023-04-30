#include <iostream>
#include <string>
using namespace std;
class marsrut
{

    string firstplace;
    string secondplace;
    float rasstoyanie;

public:
    marsrut();                       
    marsrut(string, string, float);    
    marsrut(const marsrut&);          
    ~marsrut();                      
    string get_firstplace();     
    void set_firstplace(string); 
    string get_secondplace();         
    void set_secondplace(string);     
    float get_rasstoyanie();         
    void set_rasstoyanie(float);     
    void show();                   
};
