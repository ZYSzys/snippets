#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    ifstream f("3.cpp", ios_base::in);
    ofstream of("copy.cpp", ios_base::out);
    if(f)
    {
    	string s;
    	while(f)
    	{
    		getline(f, s);
    		cout << setiosflags(ios_base::left) << setw(100) << s << resetiosflags(ios_base::left) << endl;
    		of << s << endl;
    	}
    }
    else
    {
        cout << "Error!" << endl;
    }
    of.close();
    f.close();
    return 0;
}