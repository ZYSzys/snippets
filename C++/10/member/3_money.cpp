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
    Money& operator -- ()
    {
    	a--;
    	b--;
    	c--;
        return *this;
    }
    Money operator -- (int)
    {
        Money temp = *this;
        --(*this);
        return temp;
    }
    void Display()
    {
        cout << a << " yuan " << b << " jiao " << c << " fen" << endl;
    }
};
int main()
{
    Money m1(10, 8, 5);
    Money m2 = --m1;
    Money m3 = m1--;
    cout << "m1: ", m1.Display();
    cout << "m2: ", m2.Display();
    cout << "m3: ", m3.Display();
    return 0;
}