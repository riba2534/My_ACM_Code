#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 1001000
#define M 1000000
#define ll long long
using namespace std;
int n,m,ans,k;
char map[120][120];
int vis[1<<4][120][120];//用二进制位来记录状态
int go[4][2]= {0,1,0,-1,1,0,-1,0};
struct node
{
    int x,y,st;
} a[5];
int bfs(int x,int y)
{
    node now,to;
    queue<node>q;
    now.x=x,now.y=y,now.st=0;
    mem(vis,0);
    q.push(now);
    vis[now.st][now.x][now.y]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.st==(1<<k)-1)//当到达取完所有宝物的状态，返回结果
            return vis[now.st][now.x][now.y]-1;
        for(int i=0; i<4; i++)
        {
            to.x=now.x+go[i][0];
            to.y=now.y+go[i][1];
            to.st=now.st;
            int u=0;
            for(int j=1; j<=k; j++)
                if(to.x==a[j].x&&to.y==a[j].y)
                {
                    u=j;
                    break;
                }
            if(u) to.st=now.st|(1<<(u-1));//检查当前点是不是有宝藏，有宝藏的话标记状态
            if(to.x>=0&&to.x<n&&to.y>=0&&to.y<m&&map[to.x][to.y]!='#'&&!vis[to.st][to.x][to.y])//不越界且不碰墙且当前状态未标记
            {
                vis[to.st][to.x][to.y]=vis[now.st][now.x][now.y]+1;//改变状态吗，增加步数
                q.push(to);
            }
        }
    }
    return -1;//未搜到返回-1
}
int main()
{
    while(~scanf("%d%d",&n,&m)&&(n||m))
    {
        node s;
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(int j=0; j<m; j++)
            {
                if(map[i][j]=='@')//找出起点的坐标
                {
                    s.x=i;
                    s.y=j;
                }
            }
        }
        scanf("%d",&k);
        for(int i=1; i<=k; i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].x-=1;
            a[i].y-=1;
        }
        printf("%d\n",bfs(s.x,s.y));
    }
    return 0;
}
