#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int number;
    cin >> number;
    while(number)
    {
        cout << number % 10;
        number /= 10;
    }
    cout << endl;
    return 0;
}
