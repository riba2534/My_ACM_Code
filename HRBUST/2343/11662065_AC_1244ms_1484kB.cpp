#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
string minWindow(string S, string T)
{
    map<char, int> m;
    for(int i = 0; i < T.size(); ++ i)
         m[T[i]]++;
    int cnt = 0, l = 0, minl = 0, minsize = S.size() + 1;
    for(int r = 0; r < S.size(); ++ r)
        if(m.find(S[r]) != m.end())
        {
            if(-- m[S[r]] >= 0)
                ++ cnt;
            while(cnt == T.size())
            {
                if(r - l + 1 < minsize)
                    minl = l, minsize = r - l + 1;
                if(m.find(S[l]) != m.end())
                    if(++ m[S[l]] > 0)
                        -- cnt;
                ++ l;
            }
        }
    if(minsize>S.size())
        return "";
    return S.substr(minl, minsize);
}
int main()
{
    string s, t;
    while(cin >> s >> t)
    {
        string ans = minWindow(s, t);
        cout << ans << endl;
    }
    return 0;
}
