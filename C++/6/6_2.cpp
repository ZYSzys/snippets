#include <iostream>
using namespace std;
int fn1()
{
	static int n;
	n += 1;
	return n;
}
int main()
{
	int res;
	for(int i = 0; i < 10; i++)
	{
		res = fn1();
		cout << "n: " << res << endl;
	}
	return 0;
}
