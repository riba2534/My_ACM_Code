#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 50000+20
#define M 200010
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
int pre[N], dis[N],cnt;
void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        pre[i]=i;
        dis[i]=0;
    }
}
int find(int x)
{
    if(pre[x]==x)
        return x;
    int temp=pre[x];
    pre[x]=find(pre[x]);
    dis[x]+=dis[temp];
    return pre[x];
}
void mix(int x,int y,int s)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        pre[fy]=fx;
        dis[fy]=dis[x]+s-dis[y];
    }
    else
    {
        if(dis[y]-dis[x]!=s)
            cnt++;
    }
}
int main()
{
    int n,m,a,b,c;
    while(~scanf("%d%d",&n,&m))
    {
        cnt=0;
        init(n);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            mix(a,b,c);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
