 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define N 10000+20
#define M 1000000+10
#define ll long long
using namespace std;
int first[N],vis[N],len,n,m;
double dis[N];
struct node
{
    int u,v;
    double w;
    int next;
}g[100020];
void add_egde(int u,int v,double w)
{
    g[len].u=u;
    g[len].v=v;
    g[len].w=w;
    g[len].next=first[u];
    first[u]=len++;
}
void spfa()
{
    for(int i=1;i<=n;i++)
        dis[i]=0;
    dis[1]=1.0;
    queue<int>q;
    vis[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        vis[k]=0;
        for(int i=first[k];i!=-1;i=g[i].next)
        {
            if(dis[g[i].u]*g[i].w>dis[g[i].v])
            {
                dis[g[i].v]=dis[g[i].u]*g[i].w;
                if(!vis[g[i].v])
                {
                    q.push(g[i].v);
                    vis[g[i].v]=1;
                }
            }
        }
    }
}
int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        len=0;
        mem(vis,0);
        mem(first,-1);
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add_egde(a,b,c/100.0);
            add_egde(b,a,c/100.0);
        }
        spfa();
        printf("%lf\n",dis[n]*100);

    }

    return 0;
}
        