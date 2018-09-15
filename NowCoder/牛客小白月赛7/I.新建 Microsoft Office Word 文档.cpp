#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    set<int> s;
    set<int> s2;
    string str;
    s.insert(0);
    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "New")
        {
 
            if (s2.size() == 0)
            {
                auto it = --s.end();
                int ans = *it + 1;
                cout << ans << endl;
                s.insert(ans);
            }
            else
            {
                auto it = s2.begin();
                int ans = *it;
                cout << ans << endl;
                s.insert(ans);
                s2.erase(ans);
            }
        }
        else if (str == "Delete")
        {
            int x;
            cin >> x;
            if (s.find(x) == s.end())
            {
                cout << "Failed" << endl;
            }
            else
            {
                cout << "Successful" << endl;
                s.erase(x);
                s2.insert(x);
            }
        }
    }
    return 0;
}
/*
1
2
3
Successful
2
Failed
Successful
Successful
1
3
4
Successful
*/
