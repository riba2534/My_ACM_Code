#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=100000+20;
const int M=100000+20;
struct node
{
    node() {};
    node(int tv,int tf,int t)
    {
        v=tv,f=tf,next=t;
    };
    int v,f,next;
} e[M*2];
int tot,dis[N],first[N];
bool vis[N];
bool bfs(int s,int t)
{
    mem(dis,0);
    mem(vis,0);
    queue<int>q;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=first[u]; ~i; i=e[i].next)
        {
            if(!vis[e[i].v]&&e[i].f>0)
            {
                dis[e[i].v]=dis[u]+1;
                vis[e[i].v]=1;
                q.push(e[i].v);
            }
        }
    }
    return dis[t];
}
int dfs(int u,int t,int flow)
{
    if(u==t)return flow;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        if(dis[e[i].v]==dis[u]+1&&e[i].f>0)
        {
            int dd=dfs(e[i].v,t,min(flow,e[i].f));
            if(dd)
            {
                e[i].f-=dd;
                e[i^1].f+=dd;
                return dd;
            }
        }
    }
    dis[u]=0;
    return 0;
}
int Dinic(int s,int t)
{
    int ans=0,flow;
    while(bfs(s,t))
    {
        while(flow=dfs(s,t,INF))
            ans+=flow;
    }
    return ans;
}
void add_edge(int u,int v,int f)
{
    e[tot]=node(v,f,first[u]);
    first[u]=tot++;
    e[tot]=node(u,f,first[v]);
    first[v]=tot++;
}
void init()
{
    tot=0;
    mem(first,-1);
}

int main()
{
    int t,n,m,x,y,st,ed;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        int minn=INF,maxx=-INF;
        st=ed=-1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&x,&y);
            if(x<minn)
            {
                st=i;
                minn=x;
            }
            if(x>maxx)
            {
                ed=i;
                maxx=x;
            }
        }
        int u,v,w;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
        }
        printf("%d\n",Dinic(st,ed));
    }
    return 0;
}

