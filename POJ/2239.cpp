#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1000+20;
int e[N][N],vis[N],match[N],n;
int dfs(int u)
{
    for(int i=1; i<=7*12; i++)
    {
        if(e[u][i]&&!vis[i])
        {
            vis[i]=1;
            if(match[i]==-1||dfs(match[i]))
            {
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
int query()
{
    mem(match,-1);
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        mem(vis,0);
        if(dfs(i))sum++;
    }
    return sum;
}
int main()
{
    int k,a,b;
    while(~scanf("%d",&n))
    {

        mem(e,0);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d%d",&a,&b);
                e[i][(a-1)*12+b]=1;
            }
        }
        printf("%d\n",query());
    }
    return 0;
}
