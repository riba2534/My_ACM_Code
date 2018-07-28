//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <stdlib.h>
//#include <string>
//#include <map>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//#define inf 0x3f3f3f3f
//#define mem(a,b) memset(a,b,sizeof(a))
//const ll N=100000+20;
//struct node
//{
//    ll pos;
//    ll val;
//} a[N];
//bool cmp(node a,node b)
//{
//    return a.val<b.val;
//}
//ll vis[N];
//ll least;
//ll solve(ll i)
//{
//    ll j=a[i].pos;
//    ll minn=a[i].val;
//    vis[i]=1;
//    ll x=0,num=a[i].val;
//    while(!vis[j])
//    {
//        num+=a[j].val;
//        minn=min(minn,a[j].val);
//        vis[j]=1;
//        x++;
//        j=a[j].pos;
//    }
//    return num+min(minn*(x-1),least*(x+2)+minn);
//}
//int main()
//{
//    ll n,x,t;
//    scanf("%lld",&t);
//    while(t--)
//    {
//        scanf("%lld",&n);
//        mem(vis,0);
//        for(ll i=1; i<=n; i++)
//        {
//            scanf("%lld",&a[i].val);
//            a[i].pos=i;
//        }
//        sort(a+1,a+n+1,cmp);
//        least=a[1].val;
//        ll ans=0;
//        for(ll i=1; i<=n; i++)
//        {
//            if(!vis[i])
//            {
//                ans+=solve(i);
//            }
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}
//
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
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const ll N=50000+20;
ll a[N],vis[N];
ll least;
map<ll,ll>m;
ll solve(ll i)
{
    ll j=m[a[i]];
    ll minn=a[i];
    vis[i]=1;
    ll x=0,num=a[i];
    while(i!=j)
    {
        num+=a[j];
        minn=min(minn,a[j]);
        vis[j]=1;
        x++;
        j=m[a[j]];
    }
    return num+min(minn*(x-1),least*(x+2)+minn);
}
int main()
{
    mem(vis,0);
    ll n,x;
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        m[a[i]]=i;
    }
    sort(a+1,a+n+1);
    least=a[1];
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            ans+=solve(i);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
