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
const int N=1000+20;
int vis[N],match[N],e[N][N],n,m;
int dfs(int u)
{
    for(int i=1; i<=n; i++)
    {
        if(e[u][i]&&!vis[i])
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
void folyd()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            if(e[i][k])
                for(int j=1; j<=n; j++)
                    if(e[k][j])
                        e[i][j]=1;
}
int main()
{
    int a,b;
    while(~scanf("%d%d",&n,&m)&&(n||m))
    {
        mem(e,0);
        if(m==0)
        {
            printf("%d\n",n);
            continue;
        }
        while(m--)
        {
            scanf("%d%d",&a,&b);
            e[a][b]=1;
        }
        folyd();
        printf("%d\n",n-query());
    }
    return 0;
}
