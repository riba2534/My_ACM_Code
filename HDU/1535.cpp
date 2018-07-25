#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000000+10
#define LL long long
using namespace std;
int n,m,len1,len2;
struct node
{
    int v,w,next;
}G[N],E[N];
int first1[N],first2[N],dis[N],vis[N];
void add_1(int u,int v,int w)
{
    G[len1].v = v, G[len1].w = w;
    G[len1].next = first1[u];
    first1[u] = len1++;
}
void add_2(int u,int v,int w)
{
    E[len2].v = v, E[len2].w = w;
    E[len2].next = first2[u];
    first2[u] = len2++;
}
void spfa1(int st)
{
    for(int i=0;i<=n;i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
    vis[st]=1;
    dis[st]=0;
    queue<int>q;
    q.push(st);
    while(!q.empty())
    {
        st=q.front();
        q.pop();
        vis[st]=0;
        for(int i=first1[st];i!=-1;i=G[i].next)
        {
            if(dis[G[i].v]>dis[st]+G[i].w)
            {
                dis[G[i].v]=dis[st]+G[i].w;
                if(!vis[G[i].v])
                {
                    vis[G[i].v]=1;
                    q.push(G[i].v);
                }

            }
        }
    }
}
void spfa2(int st)
{
    for(int i=0;i<=n;i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
    vis[st]=1;
    dis[st]=0;
    queue<int>q;
    q.push(st);
    while(!q.empty())
    {
        st=q.front();
        q.pop();
        vis[st]=0;
        for(int i=first2[st];i!=-1;i=E[i].next)
        {
            if(dis[E[i].v]>dis[st]+E[i].w)
            {
                dis[E[i].v]=dis[st]+E[i].w;
                if(!vis[E[i].v])
                {
                    vis[E[i].v]=1;
                    q.push(E[i].v);
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
        len1=1;len2=1;
        mem(first1,-1);mem(first2,-1);
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add_1(a,b,c);
            add_2(b,a,c);//建立反向边
        }
        LL sum=0;
        spfa1(1);//从1到各个顶点的
        for(int i=1;i<=n;i++)
            sum+=dis[i];
        spfa2(1);//反向边从各个顶点到1的
        for(int i=1;i<=n;i++)
            sum+=dis[i];
        printf("%lld\n",sum);
    }
    return 0;
}
