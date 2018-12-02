#include <iostream>
#include <algorithm>
using namespace  std;
void f1()
{
	static int i = 100;
	cout << "i: " << i++ << endl;
}
void f2()
{
	int i = 100;
	cout << "i: " << i++ << endl;
}
int main()
{
	for(int k = 0; k < 5; k++)
	{
		f1();
	}
	cout << endl;
	for(int k = 0; k < 5; k++)
	{
		f2();
	}
	return 0;
}
