#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
const ll N=100+20;
const ll mod=1e9+7;
ll e[N][N],n;
ll go[4][2]= {1,0,-1,0,0,1,0,-1};
ll dp[N][N];
ll step[N][N];
struct node
{
    ll x,y,w;
    node() {}
    node(ll _x,ll _y,ll _w)
    {
        x=_x;
        y=_y;
        w=_w;
    }
    bool friend operator < (node a,node b)
    {
        return a.w>b.w;
    }
};
void bfs()
{
    dp[1][1]=e[1][1];
    priority_queue<node>q;
    q.push(node(1,1,e[1][1]));
    while(!q.empty())
    {
        node now=q.top();
        q.pop();
        if(dp[now.x][now.y]<now.w)continue;
        for(ll i=0; i<4; i++)
        {
            ll xx=now.x+go[i][0];
            ll yy=now.y+go[i][1];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=n-xx+1&&dp[now.x][now.y]+e[xx][yy]<dp[xx][yy])
            {
                dp[xx][yy]=dp[now.x][now.y]+e[xx][yy];
                q.push(node(xx,yy,dp[xx][yy]));
            }
        }
    }
}
ll dfs(ll x,ll y)
{
    if(step[x][y])return step[x][y];
    ll sum=0;
    for(ll i=0; i<4; i++)
    {
        ll xx=x+go[i][0];
        ll yy=y+go[i][1];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=n-xx+1&&dp[x][y]==dp[xx][yy]+e[x][y])
            sum+=dfs(xx,yy)%mod;
    }
    return step[x][y]=sum;
}
int main()
{
    while(scanf("%lld",&n)&&n)
    {
        for(ll i=1; i<=n; i++)
            for(ll j=1; j<=n; j++)
                scanf("%lld",&e[i][j]);
        for(ll i=1; i<=n; i++)
            for(ll j=n-i; j>=1; j--)
            {
                ll x=n-j+1;
                ll y=n-i+1;
                e[i][j]+=e[x][y];
            }
        mem(dp,inf);
        mem(step,0);
        bfs();
        ll minn=inf;
        for(ll i=1; i<=n; i++)
            minn=min(minn,dp[i][n-i+1]);
        step[1][1]=1;
        ll ans=0;
        for(ll i=1; i<=n; i++)
            if(dp[i][n-i+1]==minn)
                ans+=dfs(i,n-i+1)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
