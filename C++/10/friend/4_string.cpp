#include <iostream>
#include <string>
using namespace std;
class String
{
public:
	String(string str) {s = str;}
	friend String& operator += (String &a, String &b);
	void Display()
	{
		cout << s << endl;
	}
private:
	string s;
};
String& operator += (String &a, String &b)
{
	a.s += b.s;
	return a;
}
int main()
{
	String s1("software and "), s2("hardware");
	s1 += s2;
	s1.Display();
	return 0;
}