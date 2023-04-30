#pragma once 
class Pair
{
protected:
    int first;
    int second;

public:
    Pair(int f, int s) : first(f), second(s) {}
    void set_first(int f)
    {
        first = f;
    }
    void set_second(int s)
    {
        second = s;
    }
    int get_first() const
    {
        return first;
    }
    int get_second() const
    {
        return second;
    }
    virtual int product() const
    {
        return first * second;
    }
    virtual ~Pair() {}    
};
