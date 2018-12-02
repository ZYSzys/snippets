#include <iostream>
#include <string>
using namespace std;
class String
{
public:
	String(string str) {s = str;}
	String& operator += (String &b)
	{
		s += b.s;
		return *this;
	}
	void Display()
	{
		cout << s << endl;
	}
private:
	string s;
};
int main()
{
	String s1("software and "), s2("hardware");
	s1 += s2;
	s1.Display();
	return 0;
}