#include <iostream>
#include <algorithm>
using namespace std;
int Maxl(int x,int y)
{
    return max(x, y);
}
int Maxl(int x, int y, int z)
{
    return max(max(x, y), z);
}
float Maxl(float x, float y)
{
    return max(x, y);
}
double Maxl(double x, double y, double z)
{
    return max(max(x, y), z);
}
int main()
{
    switch(0)
    {
    	case 0:
    	int x, y;
    	cout << "Input int x, y: ";
	    cin >> x >> y;
    	cout << "The max of x and y is " << Maxl(x, y) << endl;
    	case 1:
    	int X, Y, Z;
    	cout << "Input int X, Y, Z: ";
	    cin >> X >> Y >> Z;
    	cout << "The max of X and Y ans Z is " << Maxl(X, Y, Z) << endl;
    	case 2:
    	float a, b;
    	cout << "Input float a, b: ";
	    cin >> a >> b;
    	cout << "The max of a and b is " << Maxl(a, b) << endl;
    	case 3:
    	double A, B, C;
    	cout << "Input double A, B, C: ";
	    cin >> A >> B >> C;
    	cout << "The max of A and B and C is " << Maxl(A, B, C) << endl;
    }
    return 0;
}
