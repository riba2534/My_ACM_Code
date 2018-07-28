#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=200000+20;
int in[N],out[N],a[N],times,x;
int sum[N<<2],lazy[N<<2];
vector<int>e[N];
void dfs(int rt)
{
    in[rt]=times;
    for(auto i:e[rt])
    {
        times++;
        dfs(i);
    }
    out[rt]=times;
}
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int rt,int m)
{
    if(lazy[rt])
    {
        lazy[rt<<1]^=lazy[rt];
        lazy[rt<<1|1]^=lazy[rt];
        sum[rt<<1]=(m-(m>>1))-sum[rt<<1];
        sum[rt<<1|1]=(m>>1)-sum[rt<<1|1];
        lazy[rt]=0;
    }
}
void build(int l,int r,int rt)
{
    lazy[rt]=0;
    if(l==r)
    {
        sum[rt]=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]^=1;
        sum[rt]=(r-l+1)-sum[rt];
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,lson);
    if(R>m) update(L,R,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return sum[rt];
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    int ans=0;
    if(L<=m) ans+=query(L,R,lson);
    if(R>m) ans+=query(L,R,rson);
    return ans;
}


int main()
{
    char s[5];
    int n,q;
    times=1;
    scanf("%d",&n);
    for(int i=2; i<=n; i++)
    {
        scanf("%d",&x);
        e[x].push_back(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++)scanf("%d",&a[in[i]]);
    build(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s%d",s,&x);
        if(s[0]=='g')
            printf("%d\n",query(in[x],out[x],1,n,1));
        else
            update(in[x],out[x],1,n,1);
    }
    return 0;
}

