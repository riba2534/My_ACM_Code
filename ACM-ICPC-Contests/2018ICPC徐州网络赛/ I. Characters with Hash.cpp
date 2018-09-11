#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
const int N = 1e5 + 10;
char s[N];
int abs(int a, int b)
{
    if (a > b)
        return a - b;
    return b - a;
}
int get_w(int n)
{
    stringstream ss;
    string str;
    ss << n;
    ss >> str;
    return str.length();
}
void solve()
{
    int n;
    char ch[5];
    scanf("%d%s%s", &n, ch, s);
    int ans = 0, i;
    for (i = 0; i < n; i++)
    {
        int tmp = abs(ch[0], s[i]);
        if (tmp)
        {
            ans += get_w(tmp);
            i++;
            break;
        }
    }
    for (; i < n; i++)
    {
        int tmp_num = get_w(abs(ch[0], s[i]));
        if (tmp_num < 2)
            ans += 2;
        else
            ans += tmp_num;
    }
    if (!ans)
        puts("1");
    else
        printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}