#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <string>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=100+10;
int n,m,k,sx,sy,ex,ey,dx,dy;
char e[N][N];
int hp[N][N];
int go[4][2]= {1,0,-1,0,0,1,0,-1};
int vis[N][N][10];

void init(int x,int y,int c)
{
    for(int i=x-1; i>=0; i--)
    {
        if(e[i][y]=='.'||e[i][y]=='S')
        {
            hp[i][y]|=c;
            continue;
        }
        break;
    }
    for(int i=x+1; i<n; i++)
    {
        if(e[i][y]=='.'||e[i][y]=='S')
        {
            hp[i][y]|=c;
            continue;
        }
        break;
    }
    for(int i=y+1; i<m; i++)
    {
        if(e[x][i]=='.'||e[x][i]=='S')
        {
            hp[x][i]|=c;
            continue;
        }
        break;
    }
    for(int i=y-1; i>=0; i--)
    {
        if(e[x][i]=='.'||e[x][i]=='S')
        {
            hp[x][i]|=c;
            continue;
        }
        break;
    }
}
struct node
{
    int x,y,step;
    int flag;
};
int bfs(int x,int y)
{
    queue<node>q;
    node now,to;
    now.x=x,now.y=y,now.step=0,now.flag=hp[x][y];
    mem(vis,0);
    vis[x][y][now.flag]=1;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.flag==3)
            return now.step;
        for(int i=0; i<4; i++)
        {
            to.x=now.x+go[i][0];
            to.y=now.y+go[i][1];
            to.step=now.step+1;
            to.flag=now.flag|hp[to.x][to.y];
            if(to.x>=0&&to.x<n&&to.y>=0&&to.y<m&&to.step<=k&&!vis[to.x][to.y][to.flag]&&(e[to.x][to.y]=='.'||e[to.x][to.y]=='S'))
            {
                vis[to.x][to.y][to.flag]=1;
                q.push(to);
            }
        }
    }
    return -1;
}
int main()
{
    // freopen("in.txt","r",stdin);
    int q=1,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<n; i++)
        {
            scanf("%s",e[i]);
            for(int j=0; j<m; j++)
            {
                if(e[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                if(e[i][j]=='D')
                {
                    dx=i;
                    dy=j;
                }
                if(e[i][j]=='E')
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        mem(hp,0);
        init(ex,ey,2);
        init(dx,dy,1);
        printf("Case %d:\n%d\n",q++,bfs(sx,sy));
    }
    return 0;
}
