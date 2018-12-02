#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
class Laborage
{
public:
	Laborage() {}
	~Laborage(){}
	void Input();
	void Show();
private:
	int No;
	char Name[8];
	double Ssalary, Security, Fsalary;
};
void Laborage::Input()
{
	cout << "No: ";
	cin >> No;
	getchar();
	cout << "Name: ";
	string s;
	getline(cin, s);
	strcpy(Name, s.c_str());
	cout << "Ssalary: ";
	cin >> Ssalary;
	cout << "Security: ";
	cin >> Security;
	Fsalary = Ssalary - Security;
}
void Laborage::Show()
{
	cout << setiosflags(ios_base::fixed);
	cout << setiosflags(ios_base::left) << setw(8) << No << setw(8) << Name << resetiosflags(ios_base::left);
	cout << setiosflags(ios_base::right) << setw(10) << setprecision(2) << Ssalary << setw(10) << Security << setw(10) << Fsalary << resetiosflags(ios_base::right) << endl;
}

int main()
{
	Laborage a[3];
	for(int i = 0; i < 3; i++)
	{
		a[i].Input();
	}
	for(int i = 0; i < 3; i++)
	{
		a[i].Show();
	}
	return 0;
}