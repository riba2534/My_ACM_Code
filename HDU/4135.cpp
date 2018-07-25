#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
ll a[50],b[1010];//a保存n的质因子,a[0]表示质因子个数
void div(ll n)//分解质因数
{
    ll j=0;
    for(ll i=2; i*i<=n; i++)
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            a[++j]=i;
        }
    if(n>1) a[++j]=n;
    a[0]=j;
}
ll get_cnt(ll mid)//1--mid之间与n互质的数有多少个
{
    ll g=0,sum=mid,t;
    b[++g]=1;
    for(ll i=1; i<=a[0]; i++)
    {
        t=g;
        for(ll j=1; j<=g; j++)
        {
            b[++t]=b[j]*a[i]*-1;
            sum+=mid/b[t];
        }
        g=t;
    }
    return sum;
}


int main()
{
    ll t,q=1,a,b,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
        div(n);
        printf("Case #%lld: %lld\n",q++,get_cnt(b)-get_cnt(a-1));
    }
    return 0;
}
