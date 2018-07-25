#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 1000007
#define M 12357
#define ll long long
using namespace std;
const int N=105;
char map[N][N];
int vis[N][N];
int n,m,f_1,f_0,flag;
int go[4][2]= {0,1,1,0,0,-1,-1,0};
void dfs(int x,int y,char c)
{
    for(int i=0; i<4; ++i)
    {
        int xx=x+go[i][0];
        int yy=y+go[i][1];
        if(xx>=n||yy>=m||xx<0||yy<0)
        {
            if(c=='0')flag=1;
            continue;
        }
        if(map[xx][yy]==c&&!vis[xx][yy])
        {
            vis[xx][yy]=1;
            dfs(xx,yy,c);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        mem(vis,0);
        for(int i=0; i<n; ++i)
            scanf("%s",map[i]);
        f_1=0,f_0=0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(!vis[i][j])
                    if(map[i][j]=='0')
                    {
                        flag=0;
                        vis[i][j]=1;
                        dfs(i,j,map[i][j]);
                        if(!flag)f_0++;//搜到外层的0的个数
                    }
                    else
                    {
                        vis[i][j]=1;
                        dfs(i,j,map[i][j]);
                        f_1++;
                    }
        if(f_1!=1)
            printf("-1\n");
        else
        {
            if(f_0==1)
                printf("0\n");
            else if(f_0==0)
                printf("1\n");
            else
                printf("-1\n");
        }
    }
    return 0;
}
