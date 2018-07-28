#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1e4+10;
const int M=4e4+10;
int first[N],tot,vis[N],flag[N];
int n,m;
struct node
{
    int v,next;
} e[2*M];
void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(first,-1);
    mem(vis,0);
    mem(flag,0);
    tot=0;
}
int bfs(int st)
{
    queue<int>q;
    q.push(st);
    vis[st]=1;
    while(!q.empty())
    {
        int u=q.front();
        flag[u]=1;
        q.pop();
        for(int i=first[u]; ~i; i=e[i].next)
        {
            int v=e[i].v; flag[v]=1;
            if(vis[v]==0)
            {
               
                vis[v]=-vis[u];
                q.push(v);
            }
            else if(vis[u]==vis[v])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int t,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        int f=1;
        for(int i=1; i<=n; i++)
            if(!flag[i])
                if(!bfs(i))
                {
                    f=0;
                    break;
                }
        if(f)puts("Correct");
        else puts("Wrong");
    }
    return 0;
}
