#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const int N=6000+20;
int dp[N][2];
int pre[N],root;
int n;
int find(int x)
{
    return x==pre[x]?x:find(pre[x]);
}
void dfs(int x)
{
    for(int i=1; i<=n; i++)
    {
        if(pre[i]==x)
        {
            dfs(i);
            dp[x][0]+=max(dp[i][0],dp[i][1]);
            dp[x][1]+=dp[i][0];
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        mem(dp,0);
        for(int i=1; i<=n; i++)
        {
            pre[i]=i;
            scanf("%d",&dp[i][1]);
        }
        int u,v;
        while(scanf("%d%d",&u,&v)&&(u||v))
            pre[u]=v;
        root=find(1);
        pre[root]=-1;
        dfs(root);
        printf("%d\n",max(dp[root][0],dp[root][1]));
    }
    return 0;
}
