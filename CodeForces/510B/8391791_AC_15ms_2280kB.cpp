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
#define N 600+20
#define M 200010
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
char map[200][200];
int m,n,flag,t;
int go[10][2]= {{0,1},{-1,0},{0,-1},{1,0}},vis[200][200];
void dfs(int x,int y,int prex,int prey)
{
    int i,j,xx,yy;
    for(i=0; i<4; i++)
    {
        xx=x+go[i][0];
        yy=y+go[i][1];
        if(xx>=0&&xx<n&&yy>=0 && yy<m && map[xx][yy]==map[x][y])
        {
            if(xx==prex && yy==prey)
            {
                continue;
            }
            if(vis[xx][yy]==1)
            {
                flag=1;
                break;
            }
            vis[xx][yy]=1;
            dfs(xx,yy,x,y);
        }
        if(flag==1)
            break;
    }
    return;
}
int main()
{
    int i,j,u,v;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%s",map[i]);
        mem(vis,0);
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(vis[i][j]==1)
                    continue;
                flag=0;
                vis[i][j]=1;
                dfs(i,j,-1,-1);
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
