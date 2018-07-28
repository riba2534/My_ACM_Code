#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 500+20
#define M 100000+20
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int x,y;
};
char map[N][N];
int vis[N][N];
int go[4][2]= {1,0,-1,0,0,1,0,-1};
int n,m,r1,c1,r2,c2;
bool judge(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m)
        return true;
    return false;
}
bool bfs()
{
    node now,to;
    queue<node>q;
    now.x=r1,now.y=c1;
    vis[r1][c1]=1;
    q.push(now);
    while (!q.empty())
    {
        now=q.front();
        q.pop();
        if (vis[r2][c2]>=2)
            return true;
        for (int i=0; i<4; i++)
        {
            to.x=now.x+go[i][0];
            to.y=now.y+go[i][1];
            if (judge(to.x,to.y)&&((map[to.x][to.y]!='X'&&!vis[to.x][to.y])||(to.x==r2&&to.y==c2)))
            {
                q.push(to);
                vis[to.x][to.y]++;
            }
        }
    }
    return false;
}
int main()
{
    int i,j;
    while (~scanf("%d%d",&n,&m))
    {
        mem(vis,0);
        for (i=1; i<=n; i++)
        {
            scanf("%s",map[i]+1);
            for (j=1; j<=m; j++)
                if (map[i][j]=='X')
                    vis[i][j]++;
        }
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        if (bfs())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
