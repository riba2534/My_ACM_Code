#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N=200+20;
int color[N],vis[N],match[N],n,m,pre;
vector<int>G[N];
int judge()//染色法判断二分图
{
    queue<int>q;
    q.push(pre);
    color[pre]=1;
    while(!q.empty())
    {
        int v1=q.front();
        q.pop();
        for(int i=0; i<G[v1].size(); i++)
        {
            int v2=G[v1][i];
            if(color[v2]==-1)
            {
                color[v2]=-color[v1];
                q.push(v2);
            }
            else if(color[v1]==color[v2])
                return 0;
        }
    }
    return 1;
}
int dfs(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            if(match[v]==-1||dfs(match[v]))
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
    int a,b;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<N; i++)G[i].clear();
        mem(color,-1);
        mem(match,-1);
        pre=0;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            if(!pre)pre=a;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(!judge())puts("No");
        else
        {
            int sum=0;
            for(int i=1; i<=n; i++)
            {
                mem(vis,0);
                if(dfs(i))sum++;
            }
            printf("%d\n",sum/2);
        }
    }
    return 0;
}
