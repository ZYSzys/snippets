#include <iostream>
#include "weigh.h"
using namespace std;
int main()
{
	double w1, w2;
	cout << "Car's weight and Boat's weight: ";
	cin >> w1 >> w2;
	Car c(w1);
	Boat b(w2);
	cout << "Total weight: " << getTotalWeight(c, b) << endl;
	return 0;
}