#include <iostream>
using namespace std;

template <class T>
class Arr {
    T* array;
    T sum, ave;
    int size;
public:
    Arr(){array = new T;size = sum = ave = 0;}
    Arr(T *a, int s)
    {
        sum = ave = 0;
        size = s;
        array = new T [size];
        for(int i = 0; i < s; i++)
        {
            array[i] = a[i];
        }
    }
    void Show();
    void Add(T t);
    T Sum();
    T Average();
    ~Arr();
};
template <class T>
void Arr<T>::Show()
{
    for(int i = 0; i < size; i++)
        {
            cout << array[i] << '\t';
        }
        cout << endl;
}
template <class T>
void Arr<T>::Add(T t)
{
    size++;
    T* temp = new T [size];
    for(int i = 0; i < size-1; i++)
    {
        temp[i] = array[i];
    }
    temp[size-1] = t;
    delete [] array;
    array = new T[size];
    for(int i = 0; i < size; i++)
    {
        array[i] = temp[i];
    }
}
template <class T>
T Arr<T>::Sum()
{
    for(int i = 0; i < this->size; i++)
    {
        this->sum += this->array[i];
    }
    return this->sum;
}
template <class T>
T Arr<T>::Average()
{
    return this->sum /= this->size;
}
template <class T>
Arr<T>::~Arr()
{
    delete [] array;
}

int main()
{
    int a[6] = {1,2,3,4,5,6};
    Arr<int> m(a, 6);
    m.Show();
    cout << "Sum: " << m.Sum() << endl;
    cout << "Average: " << m.Average() << endl;
    
    int num = 7;
    m.Add(num);
    cout << "After add " << num << ":\n";
    m.Show();
    cout << "Sum: " << m.Sum() << endl;
    cout << "Average: " << m.Average() << endl;
    return 0;
}