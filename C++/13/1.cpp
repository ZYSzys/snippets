#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

template<class T, class InputIterator, class OutputIterator>
void Sort(InputIterator first, InputIterator last, OutputIterator res)
{
    vector<T>s;
    for(; first != last; first++)
    {
        s.push_back(*first);
    }
    sort(s.begin(), s.end());
    unique_copy(s.begin(), s.end(), res);
}

int main()
{
    cout << "Input: \n";
    Sort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}