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
const int N=500+20;
char s[N][N];
int num[N][N],e[N][N],vis[N][N],tot,n,m;
int dis[N],vis2[N];
int go[4][2]= {1,0,-1,0,0,1,0,-1};
struct node
{
    int x,y,step;
};
void bfs(int x,int y)
{
    mem(vis,0);
    node now,to;
    now.x=x,now.y=y,now.step=0;
    vis[x][y]=1;
    queue<node>q;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(num[now.x][now.y])
            e[num[x][y]][num[now.x][now.y]]=now.step;
        for(int i=0; i<4; i++)
        {
            int xx=now.x+go[i][0];
            int yy=now.y+go[i][1];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&s[xx][yy]!='#')
            {
                vis[xx][yy]=1;
                to.x=xx,to.y=yy,to.step=now.step+1;
                q.push(to);
            }
        }
    }
    return;
}
int prim()
{
    for(int i=1; i<=tot; i++)
    {
        dis[i]=inf;
        vis2[i]=0;
    }
    vis2[1]=1;
    dis[1]=0;
    int ans=0;
    for(int i=0; i<=tot; i++)
    {
        int minn=inf,k=1;
        for(int j=1; j<=tot; j++)
            if(!vis2[j]&&dis[j]<minn)
            {
                minn=dis[j];
                k=j;
            }
        vis2[k]=1;
        ans+=dis[k];
        for(int j=1; j<=tot; j++)
            if(!vis2[j]&&e[k][j]<dis[j])
                dis[j]=e[k][j];
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        tot=1;
        mem(num,0);
        scanf("%d%d\n",&m,&n);
        for(int i=0; i<n; i++)
        {
            gets(s[i]);
            for(int j=0; j<m; j++)
                if(s[i][j]=='S'||s[i][j]=='A')
                    num[i][j]=tot++;
        }
        for(int i=1; i<=tot; i++)
            for(int j=1; j<=tot; j++)
                e[i][j]=i==j?0:inf;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(num[i][j])
                    bfs(i,j);
        printf("%d\n",prim());
    }
    return 0;
}
