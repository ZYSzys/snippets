#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Score
{
private:
	string No;
	char Name[8];
	double Math, Phi, Data, Ave;
public:
	void Write();
	void Average();
	void Display();
};
void Score::Write()
{
	string m1;
	char m2[8];
	double m3, m4, m5;
	cout << "Input No: ";
	cin >> m1;
	cout << "Input Name: ";
	cin >> m2;
	cout << "Input Math: ";
	cin >> m3;
	cout << "Input Phi: ";
	cin >> m4;
	cout << "Input Data: ";
	cin >> m5;
	this->No = m1;
	strcpy(this->Name, m2);
	this->Math = m3;
	this->Phi = m4;
	this->Data = m5;
	this->Average();
}
void Score::Average()
{
	this->Ave = (this->Math+this->Phi+this->Data)/3;
}
void Score::Display()
{
	cout << this->No << '\t';
	cout << this->Name << '\t';
	cout << this->Math << '\t';
	cout << this->Phi << '\t';
	cout << this->Data << '\t';
	cout << this->Ave << endl;
}
int main()
{
	int i;
	Score s[3];
	for(i =0; i < 3; i++)
	{
		cout << "Input ---------s[" << i << "]: \n";
		s[i].Write();
	}
	cout << "No\tName\tMath\tPhi\tData\tAve\n";
	for(i =0; i < 3; i++)
	{
		s[i].Display();
	}
	return 0;
}