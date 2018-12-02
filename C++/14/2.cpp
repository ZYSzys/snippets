#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void MakeSource()
{
	string s = "source file";
	ofstream file("a.txt", ios_base::out);
	file.write(reinterpret_cast<char *>(&s), sizeof(s));
	file.close();
}
int main()
{
	MakeSource();
	ifstream is("a.txt", ios_base::in);
	ofstream file1("b.txt", ios_base::out);
	if(is)
	{
		char c = is.get();
		while(c != EOF)
		{
			file1.put(c);
			c = is.get();
		}
	}
	file1.close();
	is.close();

	ifstream iss("a.txt", ios_base::in);
	ofstream file2("c.txt", ios_base::out);
	if(iss)
	{
		string s;
		while(iss)
		{
			getline(iss, s);
			file2 << s << endl;
		}
	}
	file2.close();
	iss.close();	
	return 0;
}