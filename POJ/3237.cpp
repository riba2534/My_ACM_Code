#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
typedef long long ll;
const int N = 2e5 + 10;
const int inf=0x3f3f3f3f;
int MAX[N<<2],MIN[N<<2],flag[N<<2];
int first[N],tot,n;
int w[N],cnt;
int fa[N],siz[N],dep[N],son[N],id[N],top[N];
struct edge
{
    int u,v,w,next;
} e[N];
void add_edge(int u,int v,int w)
{
    e[tot].u=u,e[tot].v=v,e[tot].w=w;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(first,-1);
    tot=0;
    cnt=0;
}
void pushup(int rt)
{
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
    MIN[rt]=min(MIN[rt<<1],MIN[rt<<1|1]);
}
void pushdown(int rt)
{
    if(flag[rt])//此点需要操作的时候
    {
        MAX[rt<<1]*=-1;
        MIN[rt<<1]*=-1;
        swap(MAX[rt<<1],MIN[rt<<1]);
        MAX[rt<<1|1]*=-1;
        MIN[rt<<1|1]*=-1;
        swap(MAX[rt<<1|1],MIN[rt<<1|1]);
        flag[rt<<1]^=1;
        flag[rt<<1|1]^=1;
        flag[rt]=0;
    }
}
void build(int l,int r,int rt)
{
    flag[rt]=0;
    if(l==r)
    {
        MAX[rt]=MIN[rt]=w[l];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int c,int l,int r,int rt)
{
    if(l==r)
    {
        MAX[rt]=MIN[rt]=c;
        flag[rt]=0;
        return;
    }
    int m=(l+r)>>1;
    pushdown(rt);
    if(p<=m) update(p,c,lson);
    else update(p,c,rson);
    pushup(rt);
}
void ne_update(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        MAX[rt]*=-1;
        MIN[rt]*=-1;
        swap(MAX[rt],MIN[rt]);
        flag[rt]^=1;
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if(L<=m) ne_update(L,R,lson);
    if(R>m) ne_update(L,R,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return MAX[rt];
    int m=(l+r)>>1;
    pushdown(rt);
    int ans=-inf;
    if(L<=m) ans=max(ans,query(L,R,lson));
    if(R>m) ans=max(ans,query(L,R,rson));
    return ans;
}

void dfs1(int u,int f,int deep)
{
    fa[u]=f;
    siz[u]=1;
    dep[u]=deep;
    son[u]=0;//很重要
    int maxson=-1;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v==f) continue;
        dfs1(v,u,deep+1);
        siz[u]+=siz[v];
        if(siz[v]>maxson)
        {
            son[u]=v;
            maxson=siz[v];
        }
    }
}
void dfs2(int u,int topf)
{
    top[u]=topf;
    id[u]=++cnt;
    if(!son[u])
        return;
    dfs2(son[u],topf);
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int qmax(int x,int y)
{
    int ans=-inf;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        ans=max(ans,query(id[top[x]],id[x],1,n,1));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    ans=max(ans,query(id[son[x]],id[y],1,n,1));//不包含当前节点，所以是son[x]
    return ans;
}
void change(int x,int k)
{
    x--;
    update(id[e[2*x].u],k,1,n,1);//因为是双向边，所以是e[2*x].u
}
void ngate(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        ne_update(id[top[x]],id[x],1,n,1);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    ne_update(id[son[x]],id[y],1,n,1);
}
int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        init();
        for(int i=1; i<=n-1; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add_edge(a,b,c);
            add_edge(b,a,c);
        }
        dfs1(1,0,1);
        dfs2(1,1);
        for (int i = 0; i < tot; i += 2)
        {
            if (dep[e[i].u] < dep[e[i].v])
                swap(e[i].u, e[i].v);
            w[id[e[i].u]] = e[i].w;
        }
        build(1,n,1);
        char s[10];
        while(scanf("%s",s)&&s[0]!='D')
        {
            scanf("%d%d",&a,&b);
            if(s[0]=='Q')
                printf("%d\n",qmax(a,b));
            else if(s[0]=='C')
                change(a,b);
            else if(s[0]=='N')
                ngate(a,b);
        }
    }
    return 0;
}
/*
1
7
1 2 1
1 3 2
2 4 3
2 5 4
3 6 5
3 7 6
Q 1 7
N 2 7
Q 1 7
D
*/
