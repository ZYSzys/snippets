#include <iostream>
#include <algorithm>
using namespace std;
void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a, b;
	cout << "Input two numbers: ";
	cin >> a >> b;
	cout << a << '\t' << b << endl;
	if(a < b)
		Swap(&a, &b);
	cout << a << '\t' << b << endl;
	return 0;
}
