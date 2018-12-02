#include <iostream>
using namespace std;
int GetPower(int x, int y)
{
    if(!y)
    {
        return 1;
    }
    return x*GetPower(x, y-1);
}
int main()
{
    int x, y;
    cout << "Input x and y: ";
    cin >> x >> y;
    cout << x << " power " << y << " is " << ((x == 0 && y == 0) ? 1:GetPower(x, y)) << endl;;
    return 0;
}
