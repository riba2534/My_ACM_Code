 
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=100+20;
const int inf=INFINITY;
int e[N][N],maxx,minn,flag,n;
int vis[N][N];
int go[4][2]= {0,1,0,-1,1,0,-1,0};
void dfs(int x,int y,int L,int R)
{
    if(flag)return;
    if(x==n&&y==n)
    {
        flag=1;
        return;
    }
    for(int i=0; i<4; i++)
    {
        int xx=x+go[i][0];
        int yy=y+go[i][1];
        if(xx>=0&&xx<=n&&yy>=0&&yy<=n&&e[xx][yy]>=L&&e[xx][yy]<=R&&!vis[xx][yy])
        {
            vis[xx][yy]=1;
            dfs(xx,yy,L,R);
        }
    }
}
bool find(int k)
{
    for(int i=minn; i<=maxx-k; i++)
    {
        flag=0;
        if(e[1][1]<i||e[1][1]>i+k)continue;
        if(e[n][n]<i||e[n][n]>i+k)continue;
        mem(vis,0);
        dfs(1,1,i,i+k);
        if(flag)return true;
    }
    return false;
}
int erfen()
{
    int l=0,r=maxx-minn;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(find(mid))
            r=mid;
        else
            l=mid+1;
    }
    return r;
}
int main()
{
    while(~scanf("%d",&n))
    {
        maxx=0,minn=inf;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&e[i][j]);
                maxx=max(maxx,e[i][j]);
                minn=min(minn,e[i][j]);
            }
        printf("%d\n",erfen());
    }
    return 0;
}
        