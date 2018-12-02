#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map<int, int>m;
int main()
{
    int n, num;
    cout << "Input the number of num: ";
    cin >> n;
    cout << "Input " << n << " numbers(<=100):";
    while(n--)
    {
        cin >> num;
        m[num]++;
    }
    for(int i = 0; i <= 100; i++)
    {
        if(m[i])
            cout << i << ": " << m[i] << endl;
    }
    return 0;
}

