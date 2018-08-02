#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
struct node
{
    ll st,ed,cha;
} a[N];
bool cmp(node A,node B)
{
    return A.cha>B.cha;
}
int main()
{
    ll n,m,sum1=0,sum2=0;
    scanf("%lld%lld",&n,&m);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld%lld",&a[i].st,&a[i].ed);
        sum1+=a[i].st;
        sum2+=a[i].ed;
        a[i].cha=a[i].st-a[i].ed;
    }
    if(sum1<=m)
    {
        puts("0");
        return 0;
    }
    if(sum2>m)
    {
        puts("-1");
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        if(sum1<=m)
        {
            printf("%lld\n",ans);
            return 0;
        }
        sum1-=a[i].cha;
        ans++;
    }
    printf("%lld\n",ans);
    return 0;
}
