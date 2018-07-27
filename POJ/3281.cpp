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
const int N=400+20;
int g[N][N],pre[N];
bool vis[N];
int st,ed,p;
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
        for(int i=st; i<=ed; i++)
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
            v=w;
        }
    }
    return maxflow;
}
int main()
{
    int n,f,d,a,b,x;
    scanf("%d%d%d",&n,&f,&d);
    for(int i=1; i<=n; i++) g[2*i-1][2*i]=1;//拆点
    for(int i=1; i<=f; i++) g[0][2*n+i]=1;//食物的标号范围:2*n+1~2*n+f
    for(int i=1; i<=d; i++) g[2*n+f+i][2*n+f+d+1]=1;//饮料的标号范围:2*n+f+1~2*n+f+n
    st=0;
    ed=2*n+f+d+1;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a,&b);
        for(int j=1; j<=a; j++)
        {
            scanf("%d",&x);
            g[2*n+x][2*i-1]=1;
        }
        for(int j=1; j<=b; j++)
        {
            scanf("%d",&x);
            g[2*i][2*n+f+x]=1;
        }
    }
    printf("%d\n",EK(st,ed));
    return 0;
}
