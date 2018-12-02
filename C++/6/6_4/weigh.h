#ifndef weigh_h
#define weigh_h

class Boat;
class Car
{
public:
	Car(double n = 20):weight(n){}
	friend double getTotalWeight(Car &c, Boat &b);
private:
	double weight;
};
class Boat
{
public:
	Boat(double n = 30):weight(n){}
	friend double getTotalWeight(Car &c, Boat &b);
private:
	double weight;
};
double getTotalWeight(Car &c, Boat &b)
{
	return c.weight + b.weight;
}

#endif