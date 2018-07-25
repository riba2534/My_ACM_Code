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
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll N=1e5+7;
ll n;
string s[N];
ll num[30];//最后赋的值
ll mi[N];//26的次幂
ll vis[30];//标记某一个字母是否在第一位出现过
struct node
{
    ll id;
    ll num[N];//在某个位置出现的次数
    bool operator < (const node &a) const
    {
        for(ll j=100000; j>=0; j--)
            if(num[j]!=a.num[j])
                return num[j]>a.num[j];
        return 0;
    }
} p[30];
int main()
{
    ios::sync_with_stdio(false);
    ll q=1;
    mi[0]=1;
    for(ll i=1; i<=N; i++)
        mi[i]=(mi[i-1]*26)%mod;
    while(cin>>n)
    {
        //初始化
        for(ll i=0; i<26; i++)
        {
            for(ll j=0; j<=N; j++)
                p[i].num[j]=0;
            p[i].id=i;
            vis[i]=0;
        }
        //读入n组数据,从右往左记录次数
        for(ll i=0; i<n; i++)
        {
            cin>>s[i];
            ll l=s[i].size();
            if(l>1) vis[s[i][0]-'a']=1;
            for(ll k=l-1,j=0; k>=0; k--,j++)
            {
                ll t=s[i][k]-'a';
                p[t].num[j]++;
            }
        }
        //进位
        for(ll i=0; i<26; i++)
            for(ll j=0; j<=N; j++)
            {
                p[i].num[j+1]+=p[i].num[j]/26;
                p[i].num[j]%=26;
            }
        sort(p,p+26);
        for(ll i=25;i>=0;i--)
            num[p[25-i].id]=i;//排好序之后依次赋值
        ll t=25;
        while(vis[p[t].id]&&t)//判断有没有出现前导0，如果出现的话，就更改赋值的顺序
        {
            swap(num[p[t].id],num[p[t-1].id]);
            t--;
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            ll l=s[i].size();
            for(ll j=0;j<l;j++)
        ans=(ans+num[s[i][j]-'a']*mi[l-1-j]%mod)%mod;
        }
        printf("Case #%lld: %lld\n",q++,ans);
    }
    return 0;
}
