#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100;
void str_cat(char *p1, char *p2)
{
	strcat(p1, p2);
	cout << "The string: " << p1 << endl;
}
int str_cmp(char *p1, char *p2)
{
	while(*p1 == *p2)
	{
		if(*p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	return *p1 - *p2;
}
int str_len(char *p)
{
	return strlen(p);
}
int main()
{
	char p1[N], p2[N];
	cout << "Input the first string p1: ";
	cin.getline(p1, N);
	cout << "Input the second string p2: ";
	cin.getline(p2, N);
	if(str_cmp(p1, p2))
	{
		cout << (str_cmp(p1, p2)>0?"p1 > p2":"p1 < p2") << endl;
	}
	else
	{
		cout << "p1 = p2" << endl;
	}
	str_cat(p1, p2);
	cout << "Length: " << str_len(p1) << endl;
	return 0;
}
