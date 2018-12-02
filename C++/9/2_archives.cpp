#include <iostream>
#include <cstring>
using namespace std;
class Archives
{
private:
    int No;
    char Name[8];
    char Sex;
    int Age;
public:
    Archives(int n, const char name[], char s, int a)
    {
        No = n;
        strcpy(Name, name);
        Sex = s;
        Age = a;
    }
    void Show(void)
    {
        cout << "No: " << No << "\t" << "Name: " << Name << "\t" << "Sex: " << Sex << "\t" << "Age: " << Age << "\n";
    }
};

class Laborage: public Archives
{
private:
    float SSalary, Security, Fsalary;
public:
    Laborage(int n, const char name[], char s, int a, float ss, float se):Archives(n, name, s, a)
    {
        SSalary = ss;
        Security = se;
    }
    void Count()
    {
        Fsalary = SSalary - Security;
    }
    void Display()
    {
        Show();
        cout << "SSalary: " << SSalary << "\t" << "Security: " << Security << "\t" << "Fsalary: " << Fsalary << '\n';
    }
};
int main()
{
    Laborage lab(1001, "Zhou", 'M', 21, 2000, 100);
    lab.Count();
    lab.Display();
    return 0;
}