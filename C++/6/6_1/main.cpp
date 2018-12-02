#include <iostream>
#include "fn1.h"
#include "fn1.cpp"
using namespace std;
int n;
int main()
{
	cout << "Input n: ";
	cin >> n;
	fn1();
	cout << "n: " << n << endl;
	return 0;
}