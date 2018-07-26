 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int map[110][110];
int go[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};//四个方向
int ans;
int r,c,step,num;
struct node
{
    int x;
    int y;
    int sum;
} a[20000];//让搜索的顺序从最大的山依次往下搜索，然而还是超时
bool cmp(node x,node y)
{
    return x.sum>y.sum;
}
void dfs(int x,int y)
{
    if(map[x][y]+step<ans)return;
    if(map[x][y]<map[x+1][y]&&map[x][y]<map[x-1][y]&&map[x][y]<map[x][y+1]&&map[x][y]<map[x][y-1])//如果四面都是高山就代表不能搜了
    {
        ans=max(step,ans);
        return;
    }
    for(int i=0; i<4; i++)
    {
        int xx=x+go[i][0];
        int yy=y+go[i][1];
        if(xx>0&&xx<=r&&yy>0&&yy<=c&&map[xx][yy]<map[x][y])//判断越界
        {
            step++;
            dfs(xx,yy);
            step--;//避免回头路
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&r,&c);
        ans=0;
        num=0;
        for(int i=0; i<=r+1; i++)
        {
            map[i][0]=99999;
            map[i][c+1]=99999;
        }
        for(int i=0; i<=c; i++)
        {
            map[0][i]=99999;
            map[r+1][i]=99999;
        }//给外圈加一圈99999
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
            {
                scanf("%d",&map[i][j]);
                a[num].x=i;
                a[num].y=j;
                a[num].sum=map[i][j];
                num++;
            }
        sort(a,a+num,cmp);
        for(int i=0; i<num; i++)
        {
            step=1;
            dfs(a[i].x,a[i].y);
        }//依次深搜
        printf("%d\n",ans);
    }
    return 0;
}
        