#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100+20;
int e[N][N],vis[N],match[N],l[N],r[N],n;
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
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&e[i][j]);
        if(query()!=n)puts("-1");
        else
        {
            int num=0;
            for(int i=1; i<=n; i++)
                if(match[i]!=i)
                    for(int j=1; j<=n; j++)
                        if(match[j]==i)
                        {
                            l[num]=i;
                            r[num++]=j;
                            swap(match[i],match[j]);
                            break;
                        }
            printf("%d\n",num);
            for(int i=0; i<num; i++)
                printf("C %d %d\n",l[i],r[i]);
        }
    }
    return 0;
}
