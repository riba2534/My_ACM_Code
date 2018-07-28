#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 100+20
#define M 1000000+10
#define LL long long
using namespace std;
int map[110][110],n,m;
int go[4][2]= {1,0,-1,0,0,1,0,-1};
int dfs(int x,int y)
{
    if(map[x][y]==0)
        return 0;
    map[x][y]=0;
    int step=1,xx,yy;
    for(int i=0; i<4; i++)
    {
        xx=x+go[i][0];
        yy=y+go[i][1];
        if(xx<=n&&xx>=1&&yy>=1&&yy<=m&&map[xx][yy]==1)
        {
            step+=dfs(xx,yy);
            map[xx][yy]=0;
        }

    }
    return step;
}
int main()
{
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        int sum=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d",&map[i][j]);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(map[i][j]==1)
                {
                    int num=dfs(i,j);
                    sum=max(sum,num);
                }

        printf("%d\n",sum);
    }
    return 0;
}
