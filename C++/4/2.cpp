#include <iostream>
#include <algorithm>
using namespace std;
int n = 100;
int main()
{
	int i = 200, j = 300;
	for(int k = 0; k < 1; k++)
	{
		int i = 1, j = 2;
		int n = i + j;
		cout << "i = " << i << "\tj = " << j << "\tn = " << n << endl;
	}
	n = i + j;
	cout << "i = " << i << "\tj = " << j << "\tn = " << n << endl;
	return 0;
}
