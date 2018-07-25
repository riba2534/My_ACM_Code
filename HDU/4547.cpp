#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100000+7;
const int M=2*N;
int pre[N],first[N],first2[N],tot,tot2;
bool vis[N];//标记有没有询问
int n;
int fa[N],ans[N],cnt;
int vis2[N],dis[N];
map<string,int>mp;
struct edge
{
    int v,next;
} e[M];
struct Query
{
    int v,next,id,flag;
} query[M];

void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}

void add_query(int u,int v,int id,int flag)
{
    query[tot2].flag=flag;
    query[tot2].id=id;
    query[tot2].v=v;
    query[tot2].next=first2[u];
    first2[u]=tot2++;
}

int find(int x)
{
    return x==pre[x]?x:pre[x]=find(pre[x]);
}

void lca(int u,int fa)
{
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v==fa) continue;
        lca(v,u);
        pre[v]=u;
    }
    vis[u]=1;
    for(int i=first2[u]; ~i; i=query[i].next)
    {
        int v=query[i].v;
        if(vis[v])
        {
            int id=query[i].id;
            int flag=query[i].flag;
            if(flag==1)
            {
                if(u==find(v))
                    ans[id]=1;
                else if(find(u)==v)
                    ans[id]=dis[u]-dis[find(v)];
                else
                    ans[id]=dis[u]-dis[find(v)]+1;
            }
            else
            {
                int u1=v;
                int v1=u;
                if(u1==find(v1))
                    ans[id]=1;
                else if(find(u1)==v1)
                    ans[id]=dis[u1]-dis[find(v)];
                else
                    ans[id]=dis[u1]-dis[find(v)]+1;
            }
        }
    }
}



void dfs(int u,int len)
{
    vis2[u]=1;
    dis[u]=len;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(!vis2[v])
            dfs(v,len+1);
    }
}
void init()
{
    mem(first,-1);
    mem(first2,-1);
    mem(vis,0);
    mem(vis2,0);
    mem(fa,-1);
    mem(ans,0);
    tot=0;
    tot2=0;
    cnt=1;
    mp.clear();
    for(int i=1; i<=n; i++)
        pre[i]=i;
}
struct node
{
    int u,v;
} zz[N];

int main()
{
    int t,m;
    string s1,s2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1; i<n; i++)
        {
            cin>>s1>>s2;
            if(!mp[s1]) mp[s1]=cnt++;
            if(!mp[s2]) mp[s2]=cnt++;
            int a=mp[s1],b=mp[s2];
            add_edge(a,b);
            add_edge(b,a);
            fa[a]=b;
        }
        int root=1;
        while(~fa[root]) root=fa[root];
        dfs(root,0);
        for(int i=1; i<=m; i++)
        {
            cin>>s1>>s2;
            int a=mp[s1],b=mp[s2];
            zz[i].u=a,zz[i].v=b;
            add_query(a,b,i,1);
            add_query(b,a,i,2);
        }
        lca(root,root);
        for(int i=1; i<=m; i++)
        {
            int u=zz[i].u,v=zz[i].v;
            if(u==v)
                puts("0");
            else
                printf("%d\n",ans[i]);
        }
    }
    return 0;
}
