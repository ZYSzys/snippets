#include <iostream>
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
    Array operator + (const Array &b)
    {
        int c[10];
        for(int i = 0; i < 10; i++)
        {
            c[i] = a[i] + b.a[i];
        }
        return Array(c);
    }
    void Show()
    {
        for(int i = 0; i < 10; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {4,5,6,7,8,9,10,11,12,13};
    Array arr1(a), arr2(b);
    Array arr3 = arr1 + arr2;
    arr3.Show();
    return 0;
}