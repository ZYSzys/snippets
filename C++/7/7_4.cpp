#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10;
int a[N], b[N], c[N], d[N];
void Sort1(int a[])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = i+1; j < N; j++)
		{
			if(a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
	for(int i = 0; i < N; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void Sort2(int *a)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = i+1; j < N; j++)
		{
			if(a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
	for(int i = 0; i < N; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int main()
{
	cout << "Input 10 numbers: ";
	for(int i = 0; i < N; i++)
	{
		cin >> a[i];
		b[i] = c[i] = d[i] = a[i];
	}
	Sort1(a);
	Sort2(b);

	int *p = c;
	Sort1(p);
	p = d;
	Sort2(p);
	return 0;
}
