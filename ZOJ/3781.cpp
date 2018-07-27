#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 999999999
typedef long long ll;
const int N=50;
int n,m;
int num[N][N];
char s[N][N];
int go[4][2]= {1,0,-1,0,0,1,0,-1};
int first[N*N],tot,cnt;
int vis[4*N*N];
struct edge
{
    int v,next;
} e[2*4*N*N];
void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(num,-1);
    mem(first,-1);
    tot=0;
    cnt=0;
}
void dfs(int x,int y,int ct,char ch)
{
    for(int i=0; i<4; i++)
    {
        int xx=x+go[i][0];
        int yy=y+go[i][1];
        if(xx>=0&&xx<n&&yy>=0&&yy<=m)
        {
            if(s[xx][yy]==ch)
            {
                if(num[xx][yy]==-1)
                {
                    num[xx][yy]=ct;
                    dfs(xx,yy,ct,ch);
                }
            }
            else if(num[xx][yy]!=-1)
            {
                int u=ct,v=num[xx][yy];
                add_edge(u,v);
                add_edge(v,u);
            }
        }
    }
}
struct node
{
    int x,step;
};
int bfs(int x)
{
    mem(vis,0);
    vis[x]=1;
    int maxx=0;
    queue<node>q;
    node now,to;
    now.x=x,now.step=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        maxx=max(maxx,now.step);
        int u=now.x;
        to.step=now.step+1;
        for(int i=first[u]; ~i; i=e[i].next)
        {
            int v=e[i].v;
            if(!vis[v])
            {
                vis[v]=1;
                to.x=v;
                q.push(to);
            }
        }
    }
    return maxx;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0; i<n; i++)
            scanf("%s",s[i]);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(num[i][j]==-1)
                {
                    num[i][j]=cnt++;
                    dfs(i,j,cnt-1,s[i][j]);
                }
        int ans=inf;
        for(int i=0; i<cnt; i++)
        {
            int maxx=bfs(i);
            ans=min(ans,maxx);
        }
        printf("%d\n",ans);
    }
    return 0;
}