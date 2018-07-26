 
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
char a[501][501];
int map[501][501],cnt,maxx;
int go[8][2]= {{-1,1},{0,1},{1,1},{-1,0},{1,0},{-1,-1},{0,-1},{1,-1}};
int m,n,t;
void dfs(int i,int j)
{
    cnt++;
    map[i][j]=0;
    for(int k=0; k<8; k++)
    {
        int xx=i+go[k][0];
        int yy=j+go[k][1];
        if(xx>=0&&xx<m&&yy>=0&&yy<n&&map[xx][yy]==1)
        {
            dfs(xx,yy);
        }
    }
    return;
}
int main()
{
    while(~scanf("%d%d%d",&m,&n,&t))
    {
        mem(map,0);
        mem(a,0);
        int sum=0;
        cnt=0,maxx=0;
        getchar();
        for(int i=0; i<m; i++)
            gets(a[i]);
        for(int i=0; i<m; i++)
        {
            int q=0;
            for(int j=0; j<strlen(a[i]); j++)
                if(a[i][j]=='0'||a[i][j]=='1')
                    map[i][q++]=a[i][j]-'0';
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(map[i][j]==1)
                {
                    sum++;
                    dfs(i,j);
                    if(cnt>maxx)
                        maxx=cnt;
                    cnt=0;
                }
        printf("%d %d\n",sum,maxx*t);
    }
    return 0;
}
        