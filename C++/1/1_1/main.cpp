#include <iostream>
using namespace std;
int main()
{
    for(int i = 0; i < 3; i++)
    {
        if(i == 1)
        {
            cout << "    Hello!" << endl;
            continue;
        }
        for(int j = 0; j < 15; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}
