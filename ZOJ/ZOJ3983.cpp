#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
    cin >> s;
    string str = "ago";
    int ans = 1;
    do
    {
        int sum = 0;
        string temp = s;
        for (int k = 0; k < 3; k++)
        {

            int l = 0, r = temp.size() - 1;
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] == str[k])
                {
                    l = i;
                    break;
                }
            }
            for (int i = r; i >= 0; i--)
            {
                if (temp[i] == str[k])
                {
                    r = i;
                    break;
                }
            }
            string t = "";
            for (int i = 0; i <= l - 1; i++)
                t += temp[i];
            for (int i = r + 1; i < temp.size(); i++)
                t += temp[i];
            int num = 0;
            for (int i = l; i <= r; i++)
                if (temp[i] == str[k])
                    num++;
            if (num != 3)
                break;
            temp = t;
            sum++;
        }
        ans = max(ans, sum);
    } while (next_permutation(str.begin(), str.end()));
    cout << ans << endl;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}