#include <cstdio>
#include <iostream>
using namespace std;
class Money
{
private:
    int a, b, c;
public:
    Money(int t1 = 0, int t2 = 0, int t3 = 0)
    {
        a = t1, b = t2, c = t3;
    }
    friend Money& operator -- (Money &t);
    friend Money operator -- (Money &t, int);
    void Display()
    {
        cout << a << " yuan " << b << " jiao " << c << " fen" << endl;
    }
};
Money& operator -- (Money &t)
{
    t.a--, t.b--, t.c--;
    return t;
}
Money operator -- (Money &t, int)
{
    Money temp = t;
    --t;
    return temp;
}
int main()
{
    Money m1(10, 8, 5);
    Money m2 = --m1;
    Money m3 = m1--;
    m1.Display();
    m2.Display();
    m3.Display();
    return 0;
}