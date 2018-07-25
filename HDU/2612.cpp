#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int go[4][2]= {{1,0},{-1,0},{0,-1},{0,1}};
int x1,x2,y1,y2;
char map[250][250];
int f1[250][250];//第一个人的步数
int f2[250][250];//第二个人的步数
int vis[250][250];//做标记
int n,m;
struct node
{
    int x,y,s;
};
void bfs(int x,int y,int a[][250])//这里传入了第三个变量
{
    node now,to;
    queue<node>q;
    now.x=x,now.y=y,now.s=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0; i<4; i++)//循环四个方向
        {
            int xx=now.x+go[i][0];
            int yy=now.y+go[i][1];
            if(xx>=0&&yy>=0&&xx<n&&yy<m&&map[xx][yy]!='#'&&vis[xx][yy]==0)//判断越界
            {
                vis[xx][yy]=1;//标记走过的
                to.x=xx,to.y=yy,to.s=now.s+1;
                if(map[xx][yy]=='@')
                    a[xx][yy]=to.s;//如果搜到目的地就存一下
                q.push(to);
            }
        }
    }
    return;
}
int main()
{

    while(~scanf("%d%d",&n,&m))
    {
        mem(map,0);
        mem(f1,0);
        mem(f2,0);
        mem(vis,0);//初始化
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(int j=0; j<m; j++)//寻找两个人的坐标
            {
                if(map[i][j]=='Y')x1=i,y1=j;
                if(map[i][j]=='M')x2=i,y2=j;
            }
        }
        vis[x1][y1]=1;//标记
        bfs(x1,y1,f1);//搜第一个人
        mem(vis,0);//重新初始化
        vis[x2][y2]=1;//标记
        bfs(x2,y2,f2);//搜第二个人
        int min1=99999;//设置一个比较大的值
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(min1>f1[i][j]+f2[i][j]&&f1[i][j]&&f2[i][j])//有值的地方说明有kfc,找出最短的
                    min1=f1[i][j]+f2[i][j];
        printf("%d\n",min1*11);
    }
    return 0;
}

