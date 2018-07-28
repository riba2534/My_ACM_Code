#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double value[60];
int hope[60];
int ans,n;
int vis[60];
void dfs(double sum,int cishu,int v)
{
    int cur=(int)sum;
    if(sum-cur==0.0 && cur%5==0)
        ans=max(ans,v);
    if(cishu==3)
        return ;
    for(int i=0;i<n;i++)
    {
        if(vis[i])
            continue;
        vis[i]=1;
        dfs(sum+value[i],cishu+1,v+hope[i]);
        vis[i]=0;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        memset(value,0,sizeof(value));
        memset(hope,0,sizeof(hope));
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%d",&value[i],&hope[i]);
        }
        dfs(0,0,0);
        printf("%d\n", ans);
    }
    return 0;
}