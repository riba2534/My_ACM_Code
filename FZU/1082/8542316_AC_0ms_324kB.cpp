#include<stdio.h>
#include<math.h>
#include<queue>
#include<map>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<string.h>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define maxn 100+10
using namespace std;
int to[4][2]= {0,1,0,-1,1,0,-1,0};
int a[maxn][maxn],vis[maxn][maxn];
int ans,n,m,step;

void dfs(int x,int y)
{
    for(int i=0; i<4; i++)
    {
        int xx=x+to[i][0],yy=y+to[i][1];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&a[xx][yy]&&!vis[xx][yy])
        {
            step++;
            vis[xx][yy]=1;
            dfs(xx,yy);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m),n||m)
    {
        mem(vis,0);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&a[i][j]);
        ans=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(a[i][j]&&!vis[i][j])
                {
                    step=1;
                    vis[i][j]=1;
                    dfs(i,j);
                    ans=max(ans,step);
                }
        printf("%d\n",ans);
    }
    return 0;
}
