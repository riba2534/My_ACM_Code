#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

#define N 200010*5
typedef long long ll;

int n,m,tot,sz;
int head[N],to[N],nxt[N];
ll w[N],dis[N],P[66],A[N];
bool vis[N];

void Add_Edge(int x,int y,ll z)
{
    to[tot]=y;
    w[tot]=z;
    nxt[tot]=head[x];
    head[x]=tot++;
}

void Dfs(int x,ll s)
{
    vis[x]=true;
    dis[x]=s;
    for (int i=head[x]; i!=-1; i=nxt[i])
    {
        int y=to[i];
        if (vis[y]) A[++sz]=dis[y]^s^w[i];
        else Dfs(y,s^w[i]);
    }
}


void Guass()
{
    for (int i=1; i<=sz; i++)
    {
        for (int j=62; j>=0; j--)
        {
            if ((A[i]>>j)&1)
            {
                if (!P[j])
                {
                    P[j]=A[i];
                    break;
                }
                else A[i]^=P[j];
            }
        }
    }
}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int x,y;
    ll z;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%lld",&x,&y,&z);
        Add_Edge(x,y,z);
        Add_Edge(y,x,z);
    }
    Dfs(1,0);
    Guass();
    ll ans = dis[n];
    for(int i = 62; i >= 0; i--)   ans = min(ans, ans ^ P[i]);
    printf("%lld\n", ans);
    return 0;
}
