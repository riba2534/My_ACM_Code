#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

struct node
{
    int u,v,o_t,c_t,w;
} a[100009];
int first[5000],nexxt[100000],xia[5000];
int dp[5000];
int n,m,x,y;

void spfa()
{
    queue<int>q;
    q.push(x);
    memset(xia,0,sizeof(xia));
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[x]=0;
    xia[x]=1;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        xia[f]=0;
        for(int i=first[f]; i!=-1; i=nexxt[i])
        {
            if(a[i].w>a[i].o_t) continue;
            //if(xia[a[i].v]!=0) continue;
            if(a[i].o_t-dp[a[i].u]%(a[i].o_t+a[i].c_t)>=a[i].w)
            {
                if(dp[a[i].v]>dp[a[i].u]+a[i].w)
                {
                    dp[a[i].v]=dp[a[i].u]+a[i].w;
                    if(xia[a[i].v]==0)
                    {
                        q.push(a[i].v);
                        xia[a[i].v]=1;
                    }
                }
            }
            else
            {
                int h=a[i].c_t+a[i].o_t+a[i].w-dp[a[i].u]%(a[i].o_t+a[i].c_t);
                if(dp[a[i].v]>dp[a[i].u]+h)
                {
                    dp[a[i].v]=dp[a[i].u]+h;
                    if(xia[a[i].v]==0)
                    {
                        q.push(a[i].v);
                        xia[a[i].v]=1;
                    }
                }
            }
        }
    }
}

int main()
{
    int tt=1;
    while(~scanf("%d%d%d%d",&n,&m,&x,&y))
    {
        memset(first,-1,sizeof(first));
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%d%d",&a[i].u,&a[i].v,&a[i].o_t,&a[i].c_t,&a[i].w);
            nexxt[i]=first[a[i].u];
            first[a[i].u]=i;
        }
        spfa();
        printf("Case %d: %d\n",tt++,dp[y]);
    }
    return 0;
}
