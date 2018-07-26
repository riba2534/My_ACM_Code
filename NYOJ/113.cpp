 
# include <iostream>
# include <cstring>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int m = s.find("you");
        while(m != string::npos)
        {
            s[m] = 'w';
            s[m+1] = 'e';
            s.erase(s.begin() + m+2);
            m = s.find("you");
        }
        cout << s << endl;
    }
    return 0;
}        