#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=1000+20;
int e[N][N],match[N],vis[N];
int n,m,k,q=1;
int dfs(int u)
{
    for(int i=1; i<=m; i++)
    {
        if(!vis[i]&&e[u][i])
        {
            vis[i]=1;
            if(!match[i]||dfs(match[i]))
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
    mem(match,0);
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
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        mem(e,0);
        int a,b;
        for(int i=1; i<=k; i++)
        {
            scanf("%d%d",&a,&b);
            if(b>m)continue;
            e[a][b]=1;
        }
        printf("%d\n",query());
    }
    return 0;
}
