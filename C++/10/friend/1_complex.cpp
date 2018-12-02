#include <iostream>
using namespace std;
class Complex
{
private:
    int a, b;
public:
    Complex(int t1 = 0, int t2 = 0) {a = t1;b = t2;}
    friend Complex& operator -= (Complex &t1, Complex &t2);
    void Display()
    {
        cout << a << " + " << b << "i" << endl;
    }
};
Complex& operator -= (Complex &t1, Complex &t2)
{
    t1.a -= t2.a;
    t1.b -= t2.b;
	return t1;
}
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