#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1000+20;
int e[N][N],vis[N],match[N],n,temp[N][N],num;
char s[N][N];
int dfs(int u)
{
    for(int i=1; i<=num; i++)
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
    for(int i=1; i<=num; i++)
    {
        mem(vis,0);
        if(dfs(i))sum++;
    }
    return sum;
}
int main()
{
    int t,q=1;
    scanf("%d",&t);
    while(t--)
    {
        mem(temp,0);
        mem(e,0);
        mem(s,0);
        num=0;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s[i]+1);
            for(int j=1; j<=n; j++)
                if(s[i][j]=='#')
                    temp[i][j]=++num;
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(s[i][j]=='#')
                {
                    if(i!=1&&s[i-1][j]=='#') e[temp[i][j]][temp[i-1][j]]=1;
                    if(j!=1&&s[i][j-1]=='#') e[temp[i][j]][temp[i][j-1]]=1;
                    if(i!=n&&s[i+1][j]=='#') e[temp[i][j]][temp[i+1][j]]=1;
                    if(j!=n&&s[i][j+1]=='#') e[temp[i][j]][temp[i][j+1]]=1;
                }
        printf("Case %d: %d\n",q++,query()/2);
    }
    return 0;
}

