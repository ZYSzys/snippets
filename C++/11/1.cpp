#include <iostream>
#include <string>
using namespace std;

template<typename T>
T Max(T const&a, T const&b, T const&c)
{
    T t = a > b ? a : b;
    return t > c ? t : c;
}

int main()
{
    cout << Max(-5, 7, 9) << endl;
    cout << Max(-5.8, 7.1, -9.4) << endl;
    cout << Max('a', 'z', 'c') << endl;
    string a = "hello", b = "world", c = "learn";
    cout << Max(a, b, c) << endl;
    return 0;
}