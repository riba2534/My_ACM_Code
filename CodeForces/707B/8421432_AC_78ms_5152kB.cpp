#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100000+20
#define M 200010
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
long long n,m,k;
long long vis[N];
struct node
{
    long long u,v,w;
} zz[N];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int main()
{
    long long a,b,c,x;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(long long i=0; i<m; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        zz[i].u=a;
        zz[i].v=b;
        zz[i].w=c;
    }
    for(long long i=0; i<k; i++)
    {
        scanf("%lld",&x);
        vis[x]=1;
    }
    sort(zz,zz+m,cmp);
    long long sum=inf;
    for(long long i=0;i<m;i++)
    {
        if((vis[zz[i].u]&&vis[zz[i].v]==0)||(vis[zz[i].u]==0&&vis[zz[i].v]))
            sum=min(sum,zz[i].w);
    }
    if(sum==inf)
        printf("-1\n");
    else
        printf("%lld\n",sum);
    return 0;
}


