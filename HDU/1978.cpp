#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
#define mod 10000
const int N=100+20;
int n,m;
int dp[N][N],e[N][N];
int jc(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return 1;
    return 0;
}
int dfs(int x,int y)
{
    if(x==n-1&&y==m-1)
        return 1;
    if(dp[x][y]>=0)
        return dp[x][y];
    dp[x][y]=0;
    for(int i=0; i<=e[x][y]; i++)
        for(int j=0; j<=e[x][y]; j++)
            if((i+j)<=e[x][y]&&jc(x+i,y+j))
                dp[x][y]=(dp[x][y]+dfs(x+i,y+j))%mod;
    return dp[x][y];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(dp,-1);
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d",&e[i][j]);
        printf("%d\n",dfs(0,0));
    }
    return 0;
}