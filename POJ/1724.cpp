#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define N 100+20
#define M 1000000+10
#define ll long long
using namespace std;
int k,n,m,len,sum;
int first[N],dis[N][10005];
struct node1
{
    int v,dis,cost,next;
} g[10010];
struct node
{
    int num,dis,cost;
    bool friend operator < (node a,node b)
    {
        return a.dis>b.dis;
    }
};
void add_edge(int u,int v,int dis,int cost)
{
    g[len].v=v;
    g[len].dis=dis;
    g[len].cost=cost;
    g[len].next=first[u];
    first[u]=len++;
}
void dijkstra()
{
    for(int i=1; i<=n; i++)
        for(int j=0; j<=k; j++)
            dis[i][j]=inf;
    dis[1][0]=0;
    priority_queue<node>q;
    node now,to;
    now.num=1;
    now.cost=0;
    now.dis=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        if(now.num==n)
        {
            printf("%d\n",now.dis);
            return;
        }
        for(int i=first[now.num]; i!=-1; i=g[i].next)
        {
            int cost=now.cost+g[i].cost;
            if(cost>k)continue;
            if(dis[g[i].v][cost]>now.dis+g[i].dis)
            {
                dis[g[i].v][cost]=now.dis+g[i].dis;
                to.num=g[i].v;
                to.cost=cost;
                to.dis=dis[g[i].v][cost];
                q.push(to);
            }
        }
    }
    puts("-1");
}
int main()
{
    len=0;
    int a,b,c,d;
    mem(first,-1);
    scanf("%d%d%d",&k,&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add_edge(a,b,c,d);
    }
    dijkstra();
    return 0;
}
