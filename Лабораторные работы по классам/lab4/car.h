#pragma once 
#include <string> 
#include <iostream> 
using namespace std; 
class dvestorony
{
    public:
    dvestorony(void);

public:
     
    virtual ~dvestorony(void);
        
    dvestorony(string,int,int);
       
    dvestorony(const dvestorony&);

     
    string Get_naming() { return naming; }
    int Get_dlina() { return dlina; }
    int Get_shirina() { return shirina; }
     
    void Set_naming(string);
    void Set_dlina(int);
    void Set_shirina(int);
        
    dvestorony& operator=(const dvestorony&);
    friend istream &operator>>(istream &in, dvestorony &c);
    friend ostream &operator<<(ostream &out, const dvestorony &c);
    protected:
    string naming;
    int dlina;
    int shirina;
};
