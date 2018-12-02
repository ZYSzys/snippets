#include <iostream>
using namespace std;

class Complex
{
private:
	int Real, Image;
public:
	Complex(int t = 0, int i = 0){Real = t, Image = i;}
	Complex(Complex &t){Real = t.Real, Image = t.Image;}
	void Display()
	{
		cout << "The complex is " << this->Real << '+' << this->Image << 'i' << endl;
	}
};
int main()
{
	Complex c1(20, 40);
	Complex c2;
	Complex c3 = c1;
	cout << "c1: ", c1.Display();
	cout << "c2: ", c2.Display();
	cout << "c3: ", c3.Display();
	return 0;
}