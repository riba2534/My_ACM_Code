#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int go[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
char map[210][210];
int vis[210][210];
int x1,y1,x2,y2;
int n,m;
struct node
{
    int x,y,step;
    friend bool operator < (node a,node b)
    {
        return a.step>b.step;
    }
};
int bfs(int x,int y)
{
    node now,to;
    now.x=x,now.y=y,now.step=0;
    priority_queue<node>q;
    q.push(now);
    vis[x][y]=0;
    while(!q.empty())
    {
        now=q.top();
        if(now.x==x2&&now.y==y2)return now.step;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx=now.x+go[i][0];
            int yy=now.y+go[i][1];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]!=0&&map[xx][yy]!='#')
            {

                to.x=xx;
                to.y=yy;
                to.step=now.step+1;
                if(map[to.x][to.y]=='x')
                    to.step++;
                if(vis[to.x][to.y]>=to.step)
                {
                    vis[to.x][to.y]=to.step;
                    q.push(to);
                }
            }
        }
    }
    return 0;
}
int main()
{

    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(int j=0; j<m; j++)
            {
                if(map[i][j]=='r')
                {
                    x1=i;
                    y1=j;
                }
                else if(map[i][j]=='a')
                {
                    x2=i;
                    y2=j;
                }
            }
        }
        mem(vis,1);
        int aa=bfs(x1,y1);
        if(aa)
            printf("%d\n",aa);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}
