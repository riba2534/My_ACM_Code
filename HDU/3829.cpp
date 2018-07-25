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
const int N=500+20;
int vis[N],match[N],e[N][N],n,m,p;
pair<string,string>per[N];
int dfs(int u)
{
    for(int i=1; i<=p; i++)
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
    for(int i=1; i<=p; i++)
    {
        mem(vis,0);
        if(dfs(i))sum++;
    }
    return sum;
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        mem(e,0);
        for(int i=1; i<=p; i++)
        {
            cin>>per[i].first>>per[i].second;
            for(int j=1; j<i; j++)
                if((per[i].first==per[j].second)||(per[i].second==per[j].first))
                    e[i][j]=e[j][i]=1;
        }
        printf("%d\n",p-query()/2);
    }
    return 0;
}