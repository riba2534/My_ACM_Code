#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=200+20;
int p,n,m;
vector<int>G[N];
int e[N][N];
int vis[N],match[N];
int dfs(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            if(!match[v]||dfs(match[v]))
            {
                match[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0; i<N; i++)G[i].clear();
        mem(match,0);
        scanf("%d%d",&p,&n);
        for(int i=1; i<=p; i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&x);
                G[i].push_back(x);
            }
        }
        int sum=0;
        for(int i=1; i<=p; i++)
        {
            mem(vis,0);
            if(dfs(i))sum++;
        }
        puts(sum==p?"YES":"NO");
    }
    return 0;
}