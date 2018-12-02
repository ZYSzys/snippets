#include <iostream>
using namespace std;
int main()
{
	int ans = 0; 
	int a[3][3];
	cout << "Input a 3*3 two-dimensional array:\n";
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < 3; i++)
	{
		ans += (a[i][i]+a[i][2-i]);
	}
	ans -= a[1][1];
	cout << "Answer is: " << ans << endl;
	return 0;
}
