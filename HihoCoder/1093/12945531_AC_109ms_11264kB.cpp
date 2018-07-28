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
typedef long long ll;
const int N=1e5+10;
const int M=1e6+10;
int n,m;
struct SPFA
{
    int first[N],tot,vis[N],dis[N];
    void init()
    {
        mem(first,-1);
        tot=0;
    }
    struct edge
    {
        int v,w,next;
    } e[2*M];
    void add_edge(int u,int v,int w)
    {
        e[tot].v=v,e[tot].w=w;
        e[tot].next=first[u];
        first[u]=tot++;
    }
    void spfa(int st)
    {
        for(int i=1; i<=n; i++)
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
            int u=q.front();
            q.pop();
            vis[u]=0;
            for(int i=first[u]; ~i; i=e[i].next)
            {
                int v=e[i].v,w=e[i].w;
                if(dis[u]+w<dis[v])
                {
                    dis[v]=dis[u]+w;
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
} ac;
int main()
{
    int st,ed,u,v,w;
    scanf("%d%d%d%d",&n,&m,&st,&ed);
    ac.init();
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        ac.add_edge(u,v,w);
        ac.add_edge(v,u,w);
    }
    ac.spfa(st);
    printf("%d\n",ac.dis[ed]);
    return 0;
}
