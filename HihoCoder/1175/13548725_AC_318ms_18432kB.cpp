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
#define inf 0x3f3f3f3f
#define mod 142857
typedef long long ll;
const int N=1e5+20;
const int M=5e5+20;
int first[N],tot,in[N],n,m,k,a[N];
struct edge
{
    int v,next;
} e[M];
void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}
void topsort()
{
    queue<int>q;
    for(int i=1; i<=n; i++)
        if(!in[i])
            q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=first[u]; ~i; i=e[i].next)
        {
            int v=e[i].v;
            a[v]=(a[v]+a[u])%mod;
            if(!--in[v])
                q.push(v);
        }
    }
}
void init()
{
    mem(first,-1);
    mem(in,0);
    tot=0;
}
int main()
{
    int u,v,x;
    scanf("%d%d%d",&n,&m,&k);
    init();
    for(int i=1; i<=k; i++)
    {
        scanf("%d",&x);
        a[x]=1;
    }
        
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        in[v]++;
    }
    topsort();
    int ans=0;
    for(int i=1; i<=n; i++)
        ans=(ans+a[i])%mod;
    printf("%d\n",ans);
    return 0;
}
