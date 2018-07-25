#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int m,n,x1,y1,x2,y2;
char map[50][50];
int vis[50][50];
int go[4][2]= {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node
{
    int x,y,s;
    friend bool operator < (node a,node b)
    {
        return a.s>b.s;
    }
};
int check(int x,int y)
{
    if(x>=0&&x<m&&y>=0&&y<n&&!vis[x][y]&&map[x][y]!='*')
        return 1;
    return 0;
}
int bfs(int x,int y)
{
    char c;
    node now,to;
    priority_queue<node>q;
    now.x=x,now.y=y,now.s=0;
    q.push(now);
    vis[x][y]=1;
    while(!q.empty())
    {
        now=q.top();
        q.pop();
        for(int i=0; i<4; i++)
        {
            to.x=now.x+go[i][0];
            to.y=now.y+go[i][1];
            to.s=now.s+1;
            if(check(to.x,to.y)&&(map[to.x][to.y]=='-')||map[to.x][to.y]=='|')
            {
                if(to.s&1)
                {
                    if(map[to.x][to.y]=='-')
                        c='|';
                    else if(map[to.x][to.y]=='|')
                        c='-';
                }
                else
                {
                    c=map[to.x][to.y];
                }
                to.x+=go[i][0];
                to.y+=go[i][1];
                if((c=='-'&&(go[i][1]==-1||go[i][1]==1))||(c=='|'&&(go[i][0]==-1||go[i][0]==1)))
                {
                    to.s++;
                }
            }
            if(check(to.x,to.y))
            {
                if(to.x==x2&&to.y==y2)
                    return to.s;
                vis[to.x][to.y]=1;
                q.push(to);
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        mem(vis,0);
        for(int i=0; i<m; i++)
        {
            scanf("%s",map[i]);
            for(int j=0; j<n; j++)
            {
                if(map[i][j]=='S')x1=i,y1=j;//读入数据并记录起始和终点坐标
                if(map[i][j]=='T')x2=i,y2=j;
            }
        }
        printf("%d\n",bfs(x1,y1));
    }
    return 0;
}






//http://www.cnblogs.com/seayar/archive/2013/05/15/seayar.html
