#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<int, int>m;
void init()
{
	for(int i = 1; i <= 20; i++)
	{
		m[i] = 0;
	}
}
int main()
{
	vector<int>v;
	int n, num, searchValue;
	init();
	cout << "Input the number of elements: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		m[num]++;
		v.push_back(num);
	}
	for(int i = 1; i <= 20; i++)
	{
		if(m[i])
			cout << i << " has appeared " << m[i] << " times" << endl;

	}
	cout << endl << "Input the searchValue: ";
	cin >> searchValue;
	cout << searchValue << " has appeared " << count(v.begin(), v.end(), searchValue) << " times" << endl;
	return 0;
}
