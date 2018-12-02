#ifndef xyz_h
#define xyz_h
#include <iostream>
using namespace std;
class X;
class Y
{
public:
	void g(X *);
};
class X
{
public:
	X(){i = 0;}
	friend class Z;
	friend void h(X *x){x->i += 10;}
	friend void Y::g(X *x);
	void Show(){cout << "i: " << i << endl;}
private:
	int i;
};
void Y::g(X *x)
{
	x->i += 1;
}
class Z
{
public:
	void f(X *x){x->i += 5;};
};
#endif