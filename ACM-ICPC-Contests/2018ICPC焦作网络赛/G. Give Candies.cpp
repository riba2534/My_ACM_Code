#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+200;
const int mod =1e9+7;
string s;

ll mul(ll x, ll m)
{
    ll ans=1;
    while(m)
    {
        if(m&1)ans=ans*x%mod;
        x=x*x%mod;
        m>>=1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>s;
        ll ans = 0;
        for (auto v:s)
            ans = (ans * 10 + v - '0') % (mod - 1);
        ans--;
        cout << mul(2, ans) << endl;
    }

    return 0;
}
