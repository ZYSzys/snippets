#include <iostream>
using namespace std;
int main()
{
	int num, year;
	cout << "Input year: ";
	cin >> year;
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		num = 0;
	}
	else
	{
		num = 1;
	}
	switch(num)
	{
		case 0:
		cout << year << " is a leap year!" << endl;
		break;
		case 1:
		cout << year << " is not a leap year!" << endl;
		break;
	}
	return 0;
}