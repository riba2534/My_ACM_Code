#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const int N=100005+20;
int vis[N],match[N],n,m,p;
vector<int>G[N];
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
    int a,b;
    while(~scanf("%d%d",&n,&m))
    {
        mem(G,0);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        printf("%d\n",query()/2);
    }
    return 0;
}
