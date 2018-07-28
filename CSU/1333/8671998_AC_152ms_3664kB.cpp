#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100000+20
#define inf 0x3f3f3f3f
#define M 1000+20
#define LL long long
using namespace std;
int n,m,st,ed,len;
struct node
{
    int v,a,b,t,next;
}g[N];
int dis[M],first[M],vis[M];
void add_edge(int u,int v,int a,int b,int t)
{
    g[len].v=v;
    g[len].a=a;
    g[len].b=b;
    g[len].t=t;
    g[len].next=first[u];
    first[u]=len++;
}
void spfa(int st,int ed)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
    dis[st]=0;
    vis[st]=1;
    queue<int>q;
    q.push(st);
    while(!q.empty())
    {
        st=q.front();
        q.pop();
        vis[st]=0;
        for(int i=first[st];i!=-1;i=g[i].next)
        {
            int v=g[i].v;
            int a=g[i].a;
            int b=g[i].b;
            int t=g[i].t;
            int cnt=(dis[st]%(a+b)),tot;
            if(t>a)
                continue;
            if(cnt<=a)
            {
                if(cnt+t<=a)
                    tot=dis[st]+t;
                else
                    tot=a-cnt+b+t+dis[st];
            }
            else
                tot=dis[st]+a+b-cnt+t;
            if(dis[v]>tot)
            {
                dis[v]=tot;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int q=1;
    while(~scanf("%d%d%d%d",&n,&m,&st,&ed))
    {
        len=0;
        mem(first,-1);
        int u,v,a,b,t;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
            add_edge(u,v,a,b,t);
        }
        spfa(st,ed);
        printf("Case %d: %d\n",q++,dis[ed]);

    }
    return 0;
}
