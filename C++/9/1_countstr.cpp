#include <iostream>
#include <string>
using namespace std;
class Statistic
{
public:
    Statistic(string s){str = s, cnt_num = 0, cnt_cap = 0, cnt_low = 0, cnt_oth = 0;}
    void Count()
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                cnt_num++;
            }else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                cnt_cap++;
            }else if(str[i] >= 'a' && str[i] <= 'z')
            {
                cnt_low++;
            }else{
                cnt_oth++;
            }
        }
    }
    void Show()
    {
        cout << "The string contains " << cnt_num << " numbers, " << cnt_cap << " capitals, " << cnt_low << " lowercase, " << cnt_oth << " other letters." << endl;
        cout << str << endl;
    }
private:
    string str;
    int cnt_num, cnt_cap, cnt_low, cnt_oth;
};
int main()
{
    string s;
    cout << "Input a string: ";
    getline(cin, s);
    Statistic st(s);
    st.Count();
    st.Show();
    return 0;
}