#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int map[5][5];//地图
int go[4][2]= {{1,0},{-1,0},{0,-1},{0,1}};//四个方向
int pre[10000];//用来寻找父亲节点
bool vis[10][10];//标记数组
struct node
{
    int x,y,s;
};//存储坐标信息及当前步数
int bfs(int x,int y)
{
    node now,to;//先在的和将要走的
    now.x=x,now.y=y,now.s=0;
    queue<node>q;//创建队列
    vis[x][y]=1;//走过的标记为1
    q.push(now);//加入队首
    while(!q.empty())
    {
        now=q.front();
        if(now.x==4&&now.y==4)return now.s;//满足条件时返回走过的步数
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx=now.x+go[i][0];
            int yy=now.y+go[i][1];
            if(xx>=0&&yy>=0&&xx<5&&yy<5&&map[xx][yy]==0&&vis[xx][yy]==0)//判断是否越界
            {
                vis[xx][yy]=1;//标记走过的
                to.x=xx,to.y=yy,to.s=now.s+1;
                pre[xx*5+yy]=now.x*5+now.y;//存储坐标，转化成一维形式
                q.push(to);
            }
        }
    }
    return 0;
}
void myprint(int n)
{
    //printf("pre[%d]=(%d)\n",n,pre[n]);
    if(n==pre[n])return;
    myprint(pre[n]);//寻找父亲节点
    printf("(%d, %d)\n",n/5,n%5);
}//回溯打印路径
int main()
{
    mem(vis,0);
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            scanf("%d",&map[i][j]);//读入地图
    if(bfs(0,0))
    {
        printf("(0, 0)\n");//先打印0 0
        myprint(4*5+4);//从（4,4）开始回溯
    }
    else
        printf("-1\n");
    return 0;
}
