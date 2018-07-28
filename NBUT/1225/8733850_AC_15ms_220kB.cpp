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

ll pow_mod(ll a,ll n,ll m)
{
    ll ans=a;
    a=2;
    while(n)
    {
        if(n&1)
            ans=ans*a%m;
        a=a*a%m;
        n>>=1;
    }
    return ans?ans:m;
}
int main()
{
    std::ios::sync_with_stdio(false);
std::cin.tie(0);
    ll n,m,x;
    while(cin>>n>>m>>x)
    {
        ll len=min(n,x);
        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        if(n&1)
        {
            for(ll i=1; i<=len; i++)
            {
                if(i==len)
                    cout<<pow_mod(i,m,n)<<endl;
                else
                    cout<<pow_mod(i,m,n)<<" ";
            }

        }
        else
        {
            for(ll i=1; i<=len; i++)
            {
                if(i==len)
                    cout<<pow_mod(i,m,n+1)<<endl;
                else
                    cout<<pow_mod(i,m,n+1)<<" ";
            }
        }
    }
    return 0;
}


