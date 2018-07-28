#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cstring>
#include <string>
#define N 500
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m;
int map[N][N];
int go[4][2]= {0,1,0,-1,1,0,-1,0};
int dfs(int x,int y)
{
    int sum=0;
    for(int i=0; i<4; i++)
    {
        int xx=x+go[i][0];
        int yy=y+go[i][1];
        if(map[xx][yy]==0)
            sum++;
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j;
        mem(map,0);
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d",&map[i][j]);
        int sum=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(map[i][j]==1)
                    sum+=dfs(i,j);
        printf("%d\n",sum);
    }
    return 0;
}
