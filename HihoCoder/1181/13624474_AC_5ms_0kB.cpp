#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=10000+50;
int in[N];
int first[N],tot,len=0;
stack<int>s;
struct node
{
    int v,next,flag;
} e[N];
void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].flag=0;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(first,-1);
    mem(in,0);
    tot=0;
}
void dfs(int u)
{
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(!e[i].flag)
        {
            e[i].flag=1;
            e[i^1].flag=1;
            dfs(v);
        }
    }
    s.push(u);
}
int main()
{
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    init();
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
        in[u]++,in[v]++;
    }
    u=1;
    for(int i=2; i<=n; i++)
        if(in[i]&1)
        {
            u=i;
            break;
        }
    dfs(u);
    while(s.size()>1)
    {
        printf("%d ",s.top());
        s.pop();
    }
    printf("%d\n",s.top());
    return 0;
}

