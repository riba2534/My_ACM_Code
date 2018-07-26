 
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
#define N 100000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int x1,y1,x2,y2;
int map[9][9]=
{
    1,1,1,1,1,1,1,1,1,
    1,0,0,1,0,0,1,0,1,
    1,0,0,1,1,0,0,0,1,
    1,0,1,0,1,1,0,1,1,
    1,0,0,0,0,1,0,0,1,
    1,1,0,1,0,1,0,0,1,
    1,1,0,1,0,1,0,0,1,
    1,1,0,1,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1
};
int vis[12][12];
int go[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
    int x,y,s;
};
int bfs(int x,int y)
{
    node now,to;
    now.x=x,now.y=y,now.s=0;
    queue<node>q;
    vis[x][y]=1;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==x2&&now.y==y2)
            return now.s;
        for(int i=0;i<4;i++)
        {
            int xx=now.x+go[i][0];
            int yy=now.y+go[i][1];
            if(xx>=0&&xx<9&&yy>=0&&yy<9&&map[xx][yy]==0&&vis[xx][yy]==0)
            {
                vis[xx][yy]=1;
                to.x=xx,to.y=yy,to.s=now.s+1;
                q.push(to);
            }
        }
    }
    return -1;


}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(vis,0);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",bfs(x1,y1));
    }

    return 0;
}
        