#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>
#include <string>
using namespace std;
const int N = 100;

template<class T>
class Tsearch {
private:
    T a[N];
    int size;
public:
    Tsearch(T t[], int tsize)
    {
        size = tsize;
        for(int i = 0; i < tsize; i++)
            a[i] = t[i];
    }
    int search(const T &t);
    void show();
};

template<class T>
int Tsearch<T>::search(const T &t)
{
    for(int i = 0; i < N; i++)
    {
        if(a[i] == t)
            return i;
    }
    return -1;
}

template<class T>
void Tsearch<T>::show()
{
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int a[6] = {1, 3, 8, 4, 9, 10};
    Tsearch<int> searcha(a, 6);
    int s = 4;
    searcha.show();
    cout << "The index of " << s << " is: " << searcha.search(s) << endl << endl;
    
    string b[6] = {"hello", "world", "c++", "java", "c", "javascript"};
    Tsearch<string> searchb(b, 6);
    string ss = "c++";
    searchb.show();
    cout << "The index of " << ss << " is: " << searchb.search(ss) << endl;
    
    return 0;
}