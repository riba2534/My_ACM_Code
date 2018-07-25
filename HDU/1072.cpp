#include <stdio.h>  
#include <string.h>  
#include <iostream>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
using namespace std;  
int go[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};  
int map[50][50];  
//int vis[50][50];  
int n,m;  
int x1,y1,x2,y2;  
struct node  
{  
    int x,y;  
    int step;  
    int time;  
    friend bool operator < (node a,node b)//重载运算符让步数从小到大排列  
    {  
        return a.step>b.step;  
    }  
};  
int bfs(int x,int y)  
{  
    priority_queue<node>q;  
    node now,to;  
    now.x=x,now.y=y,now.step=0,now.time=6;//初始炸弹时间为6  
    map[x][y]=1;//把初始点标记为空地  
    q.push(now);  
    while(!q.empty())  
    {  
        now=q.top();  
        if(now.x==x2&&now.y==y2&&now.time>0)return now.step;//满足条件时返回步数  
        q.pop();  
        for(int i=0; i<4; i++)//遍历四个方向  
        {  
            int xx=now.x+go[i][0];  
            int yy=now.y+go[i][1];  
            if(xx>=0&&yy>=0&&xx<n&&yy<m&&map[xx][yy]!=0&&now.time>1)//判断越界及时间是否够  
            {  
                to.x=xx,to.y=yy,to.time=now.time;  
                if(map[xx][yy]==4)//遇到时间重置器时重置时间并且标记为墙  
                {  
                    to.time=6;  
                    map[xx][yy]=0;//如果已经走过这个位置了，那么用的时间肯定不是最小的，可以直接标记为0  
                }  
                else if(map[xx][yy]==1)  
                    to.time--;//每当走到一个空地时间减一  
                to.step=now.step+1;  
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
        scanf("%d%d",&n,&m);  
        for(int i=0; i<n; i++)  
            for(int j=0; j<m; j++)  
            {  
                scanf("%d",&map[i][j]);  
                if(map[i][j]==2)//起点坐标  
                {  
                    x1=i;  
                    y1=j;  
                }  
                if(map[i][j]==3)//终点坐标  
                {  
                    x2=i;  
                    y2=j;  
                }  
            }  
        int ans=bfs(x1,y1);//搜索  
        if(ans)  
            printf("%d\n",ans);  
        else  
            printf("-1\n");  
    }  
    return 0;  
}  