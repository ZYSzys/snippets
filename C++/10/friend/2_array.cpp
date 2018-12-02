#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
class Array
{
private:
    int a[10];
public:
    Array(int t[]) {
        for(int i = 0; i < 10; i++)
        {
            a[i] = t[i];
        }
    }
    friend Array& operator += (Array &t1, Array &t2);
    void Show()
    {
        for(int i = 0; i < 10; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
Array& operator += (Array &t1, Array &t2)
{
	for(int i = 0; i < 10; i++)
	{
		t1.a[i] += t2.a[i];
	}
	return t1;
}
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10]={4,5,6,7,8,9,10,11,12,13};
    Array arr1(a), arr2(b);
    arr1 += arr2;
    arr1.Show();
    return 0;
}