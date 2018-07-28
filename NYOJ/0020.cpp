#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1e5+10;
int first[N],tot,fa[N];
int n,st;
struct edge
{
    int v,next;
} e[N*2];
void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(first,-1);
    mem(fa,-1);
    tot=0;
}
void dfs(int u,int f)
{
    fa[u]=f;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v==f) continue;
        dfs(v,u);
    }
}

int main()
{
    int t,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&st);
        init();
        for(int i=1; i<=n-1; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        dfs(st,-1);
        for(int i=1; i<=n; i++)
            printf("%d ",fa[i]);
        printf("\n");
    }
    return 0;
}
