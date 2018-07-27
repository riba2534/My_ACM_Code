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
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const int N=200+20;
int g[N][N],f[N][N],pre[N];//分别代表残余网络，实流网络，前驱数组
bool vis[N];//标记数组
int n,m;//点数和边数
bool bfs(int s,int t)
{
    mem(pre,-1);
    mem(vis,false);
    queue<int>q;
    vis[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0; i<=n; i++)
        {
            if(!vis[i]&&g[now][i]>0)
            {
                vis[i]=true;
                pre[i]=now;
                if(i==t)
                    return true;
                q.push(i);
            }
        }
    }
    return false;
}
int EK(int s,int t)
{
    int v,w,d,maxflow=0;
    while(bfs(s,t))
    {
        v=t;
        d=inf;
        while(v!=s)
        {
            w=pre[v];
            d=min(d,g[w][v]);
            v=w;
        }
        maxflow+=d;
        v=t;
        while(v!=s)
        {
            w=pre[v];
            g[w][v]-=d;
            g[v][w]+=d;
            if(f[v][w]>0)
                f[v][w]-=d;
            else
                f[w][v]+=d;
            v=w;
        }
    }
    return maxflow;
}
int main()
{
    int np,nc,a,b,c;
    while(~scanf("%d%d%d%d",&n,&np,&nc,&m))
    {
        mem(g,0);
        while(m--)
        {
            while(getchar()!='(');
            scanf("%d,%d)%d",&a,&b,&c);
            g[a+1][b+1]+=c;
        }
        while(np--)
        {
            while(getchar()!='(');
            scanf("%d)%d",&a,&c);
            g[0][a+1]+=c;
        }
        while(nc--)
        {
            while(getchar()!='(');
            scanf("%d)%d",&a,&c);
            g[a+1][n+1]+=c;
        }
        n++;
        printf("%d\n",EK(0,n));
    }
    return 0;
}
