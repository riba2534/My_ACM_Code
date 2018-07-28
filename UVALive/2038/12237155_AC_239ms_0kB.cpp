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
const int N=2000+20;
int n;

vector<int>G[N];

int match[N],vis[N];
int dfs(int u)
{
    for(int i=0; i<(int)G[u].size(); i++)
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
    for(int i=0; i<n; i++)
    {
        mem(vis,0);
        if(dfs(i))
            sum++;
    }
    return sum;
}
int main()
{
    int u,v,m;
    while(~scanf("%d",&n))
    {
        mem(G,0);
        for(int i=1; i<=n; i++)
        {
            scanf("%d:(%d)",&u,&m);
            while(m--)
            {
                scanf("%d",&v);
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        printf("%d\n",query()/2);
    }
    return 0;
}

//int main()
//{
//    int u,v,k;
//    while(~scanf("%d",&n))
//    {
//        mem(G,0);
//        for(int cs=1; cs<=n; cs++)
//        {
//            scanf("%d:(%d)",&u,&k);
//            for(int i=1; i<=k; i++)
//            {
//                scanf("%d",&v);
//                G[u].push_back(v);
//                G[v].push_back(u);
//            }
//        }
//        printf("%d\n",query()/2);
//    }
//    return 0;
//}
