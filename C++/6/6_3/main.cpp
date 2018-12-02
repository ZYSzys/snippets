#include <iostream>
#include "xyz.h"
using namespace std;
int main()
{
	X x;
	Y y;
	y.g(&x);
	x.Show();
	Z z;
	h(&x);
	x.Show();
	z.f(&x);
	x.Show();
	return 0;
}
