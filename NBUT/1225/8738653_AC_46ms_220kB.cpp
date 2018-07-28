#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+20
#define mod 10007
#define M 1000000+10
#define ll long long
using namespace std;
ll temp,ans;
ll pow_mod(ll a,ll b,ll c)
{
    ll s=1;
    a=a%c;
    while(b!=0)
    {
        if(b&1)
            s=s*a%c;
        a=a*a%c;
        b>>=1;
    }
    return s;
}
int main()
{
    ll n,m,x;
    while(cin>>n>>m>>x)
    {
        if(n%2==0)n++;
        temp=pow_mod(2,m,n);
        ans=temp;
        cout<<temp;
        for(ll i=2; i<=x; i++)
        {
            ans+=temp;
            ans%=n;
            cout<<" "<<ans;
        }
        puts("");
    }
    return 0;
}