 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int go[6][3]= {{0,0,1},{0,1,0},{1,0,0},{0,0,-1},{0,-1,0},{-1,0,0}};//六个方向
int map[51][51][51];
int vis[51][51][51];
int a,b,c,T;
int abs(int x)//绝对值
{
    return x<0?-x:x;
}
struct node
{
    int x,y,z;
    int step;
    friend bool operator < (node a,node b)//重载运算符让步数从小到大排列
    {
        return a.step>b.step;
    }
};
int bfs(int x,int y,int z)
{
   queue<node>q;
    node now,to;
    now.x=x,now.y=y,now.z=z,now.step=0;
    q.push(now);
    vis[x][y][z]=1;
    while(!q.empty())
    {
        now=q.front();
        if(now.x==a-1&&now.y==b-1&&now.z==c-1&&now.step<=T)return now.step;//步数小于等于魔王火来的时间返回步数
        q.pop();
        for(int i=0; i<6; i++)
        {
            int xx=now.x+go[i][0];
            int yy=now.y+go[i][1];
            int zz=now.z+go[i][2];
            if(xx>=0&&yy>=0&&zz>=0&&xx<a&&yy<b&&zz<c&&map[xx][yy][zz]!=1&&vis[xx][yy][zz]==0)
            {
                to.x=xx,to.y=yy,to.z=zz;
                vis[xx][yy][zz]=1;
                to.step=now.step+1;
                if(abs(to.x-a+1)+abs(to.y-b+1)+abs(to.z-c+1)+to.step>T)continue;//剪枝，如果当前位置要走到终点的步数大于魔王回来的时间剪掉
                q.push(to);
            }
        }
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(map,0);
        mem(vis,0);
        scanf("%d%d%d%d",&a,&b,&c,&T);
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                for(int k=0; k<c; k++)
                    scanf("%d",&map[i][j][k]);
        int ans=bfs(0,0,0);//搜索
        if(map[a-1][b-1][c-1])//坑点，终点竟然可能是墙。。小心撞死
        {
            printf("-1\n");
            continue;
        }
        if(ans)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
        