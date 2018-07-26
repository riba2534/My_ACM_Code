 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int map[1500][1500];
int w,h;
int go[4][2]= {{1,0},{-1,0},{0,-1},{0,1}};
struct node
{
    int x,y;
};
void bfs(int x,int y)
{
    queue<node>q;
    node now;
    now.x=x,now.y=y;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx=now.x+go[i][0];
            int yy=now.y+go[i][1];
            if(xx>=0&&xx<=h+1&&yy>=0&&yy<=w+1&&map[xx][yy]>0)
            {
                map[xx][yy]=0;
                node to;
                to.x=xx,to.y=yy;
                q.push(to);

            }
        }
    }
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(map,0);
        scanf("%d%d",&w,&h);
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <=w; j++)
                scanf("%d",&map[i][j]);
        for(int i=0; i<=h; i++)
            map[i][0]=map[i][w+1]=1;
        for(int i=0; i<=w; i++)
            map[0][i]=map[h+1][i]=1;
        bfs(0,0);
        for(int i = 1; i <= h; i++)
            for(int j = 1; j <= w; j++)
            {
                if(j == w)
                    printf("%d\n",map[i][j]);
                else
                    printf("%d ",map[i][j]);
            }
    }
    return 0;
}
        