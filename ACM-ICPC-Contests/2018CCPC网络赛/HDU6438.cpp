#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
const ll N = 1e5 + 40;
priority_queue<ll, vector<ll>, greater<ll>> q;
unordered_map<ll, ll> mp;
void solve()
{
    while (!q.empty())
        q.pop();
    mp.clear();
    ll n, x, ans = 0, cnt = 0;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &x);
        if (q.empty() || x <= q.top())
        {
            q.push(x);
        }
        else
        {
            ans += x - q.top();
            cnt++;
            if (mp[q.top()] != 0)
            {
                cnt--;
                mp[q.top()]--;
            }
            q.pop();
            q.push(x), q.push(x);
            mp[x]++;
        }
    }
    printf("%lld %lld\n", ans, cnt * 2);
}
int main()
{
    // freopen("in.txt", "r", stdin);
    ll t;
    scanf("%lld", &t);
    while (t--)
        solve();

    return 0;
}
