#include <iostream>
#include <vector>
using namespace std;
const int N = 10;
int a[N];
void t1()
{
    double ans = 0;
    for(int i = 0; i < N; i++)
    {
        ans += a[i];
    }
    cout << "t1: " << (double)ans/N << endl;;
    return;
}
void t2()
{
    double ans = 0;
    for(int i = 0; i < N; i++)
    {
        ans += *(a+i);
    }
    cout << "t2: " << (double)ans/N << endl;
    return;
}
void t3()
{
    double ans = 0;
    for(int *i = a; i < (a+N); i++)
    {
        ans += *i;
    }
    cout << "t3: " << (double)ans/N << endl;
    return;
}
void t4()
{
    double ans = 0;
    int k = 1;
    for(int &i = a[0]; k <= N; i = *(&i+k++))
    {
        ans += i;
    }
    cout << "t4: " << (double)ans/N << endl;
    return;
}
int main()
{
    cout << "Input 10 numbers: ";
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    t1();
    t2();
    t3();
    t4();
    return 0;
}