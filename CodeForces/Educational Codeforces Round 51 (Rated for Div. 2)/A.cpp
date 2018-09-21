#include <bits/stdc++.h>
using namespace std;
int getint(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 1;
    else if (ch >= '0' && ch <= '9')
        return 2;
    else if (ch >= 'A' && ch <= 'Z')
        return 3;
}
char getch(int n)
{
    if (n == 1)
        return 'a';
    if (n == 2)
        return '0';
    if (n == 3)
        return 'A';
}
void solve()
{
    map<int, int> mp;
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.length(); i++)
        mp[getint(s[i])]++;
    if (mp[1] && mp[2] && mp[3])
        cout << s << endl;
    else
    {
        vector<int> sum;
        a = mp[1], b = mp[2], c = mp[3];
        if (a == 0)
            sum.push_back(1);
        if (b == 0)
            sum.push_back(2);
        if (c == 0)
            sum.push_back(3);
        if (sum.size() == 1)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (mp[getint(s[i])] >= 2)
                {
                    s[i] = getch(sum[0]);
                    break;
                }
            }
            cout << s << endl;
        }
        else
        {
            int a = sum[0], b = sum[1];
            s[0] = getch(a), s[1] = getch(b);
            cout << s << endl;
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
