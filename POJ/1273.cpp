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
        for(int i=1; i<=n; i++)
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
//            if(g[w][v]<d)
//                d=g[w][v];
            d=min(g[w][v],d);
            v=w;
        }
        maxflow+=d;
        v=t;
        while(v!=s)
        {
            w=pre[v];
            g[w][v]-=d;
            g[v][w]+=d;
//            if(f[v][w]>0)
//                f[v][w]-=d;
//            else
//                f[w][v]+=d;
            v=w;
        }
    }
    return maxflow;
}
int main()
{
    int a,b,c;
    while(~scanf("%d%d",&m,&n))
    {
        mem(g,0);
       // mem(f,0);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            g[a][b]+=c;
        }
        printf("%d\n",EK(1,n));
    }
    return 0;
}
