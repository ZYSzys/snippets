#include <iostream>
using namespace std;

template <class T>
class Cal {
    T *num;
    int size;
public:
    Cal(T *n, int l)
    {
        num = new T[l];
        size = l;
        for(int i = 0; i < size; i++)
        {
            num[i] = n[i];
        }
    }
    Cal(Cal &c)
    {
        size = c.size;
        num = new T[size];
        for(int i = 0; i < size; i++)
        {
            num[i] = c.num[i];
        }
    }
    ~Cal()
    {
        delete [] num;
    }
    T Mul()
    {
        T s = 1;
        for(int i = 0; i < size; i++)
        {
            s *= num[i];
        }
        return s;
    }
    T Add()
    {
        T s = 0;
        for(int i = 0; i < size; i++)
        {
            s += num[i];
        }
        return s;
    }
};

template <class T>
T Multiply(T *n, int size) {
    T s = 1;
    for(int i = 0; i < size; i++)
    {
        s *= n[i];
    }
    return s;
}

template <class T>
T Accumulate(T *n, int size) {
    T s = 0;
    for(int i = 0; i < size; i++)
    {
        s += n[i];
    }
    return s;
}

int main()
{
    int a[4] = {1,2,3,4};
    Cal<int>cal1(a, 4);
    cout << "Template class(int): " << cal1.Mul() << '\t' << cal1.Add() << endl;
    cout << "Template function(int): " << Multiply(a, 4) << '\t' << Accumulate(a, 4) << endl << endl;
    /*
    double b[5] = {1.2, 5.0, 3.0, 4.0, 2.0};
    Cal<double>cal2(b, 5);
    cout << "Template class(double): " << cal2.Mul() << '\t' << cal2.Add() << endl;
    cout << "Template function(double): " << Multiply(b, 5) << '\t' << Accumulate(b, 5) << endl;
    */
    return 0;
}