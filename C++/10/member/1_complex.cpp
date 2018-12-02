#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;
public:
    Complex(int t1 = 0, int t2 = 0) {a = t1;b = t2;}
    Complex& operator -= (const Complex &t)
    {
        a -= t.a;
        b -= t.b;
        return *this;
    }
    void Display()
    {
        cout << a << " + " << b << "i" << endl;
    }
};
int main()
{
    Complex c1(10, 20), c2(15, 30);
    c2 -= c1;
    cout << "c1: ";
    c1.Display();
    cout << "c2: ";
    c2.Display();
    return 0;
}