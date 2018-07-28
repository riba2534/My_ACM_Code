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
typedef pair<int,int> pir;
const int N=1e5+10;
const int M=1e6+10;
int first[N],tot;
int n,m,dis[N],vis[N];
priority_queue<pir,vector<pir>,greater<pir> >q;
struct edge
{
    int v,w,next;
} e[M*2];

void add_edge(int u,int v,int w)
{
    e[tot].v=v,e[tot].w=w;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(first,-1);
    tot=0;
    mem(dis,inf);
}
void prim()
{
    int cnt=0,sum=0;
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty()&&cnt<n)
    {
        int d=q.top().first,u=q.top().second;
        q.pop();
        if(!vis[u])
        {
            cnt++;
            sum+=d;
            vis[u]=1;
            for(int i=first[u]; ~i; i=e[i].next)
                if(e[i].w<dis[e[i].v])
                {
                    dis[e[i].v]=e[i].w;
                    q.push(make_pair(dis[e[i].v],e[i].v));
                }
        }
    }
    printf("%d\n",sum);
}

int main()
{
    int u,v,w;
    scanf("%d%d",&n,&m);
    init();
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    prim();
    return 0;
}
