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
#define ll long long
using namespace std;
const int N=1e3+5;
vector<int>f[N];
int vis[N],dis[N][N];
int n,m,pos;
void dfs(int u)
{
    vis[u]=1;
    dis[pos][u]=1;
    for(int i=0; i<f[u].size(); i++)
    {
        int v=f[u][i];
        if(!vis[v])
            dfs(v);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            f[i].clear();
        int a,b;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&a,&b);
            f[a].push_back(b);
        }
        mem(dis,0);
        int flag=1;
        for(int i=1; i<=n; i++)
        {
            mem(vis,0);
            pos=i;
            dfs(i);
        }
        for(int i=1; i<=n; i++)
            for(int j=i+1; j<=n; j++)
            {
                if(!dis[i][j]&&!dis[j][i])
                {
                    flag=0;
                    break;
                }
            }
        if(flag)
            puts("I love you my love and our love save us!");
        else
            puts("Light my fire!");
    }
    return 0;
}
