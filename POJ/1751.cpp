#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+10
#define M 1000000+10
#define LL long long
using namespace std;
int pre[N];
int n,m,len,cnt;
struct node
{
    int u,v;
    double w;
} G[M];
struct zzz
{
    int x,y;
} zz[M];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
void init()
{
    for(int i=1; i<=n; i++)
        pre[i]=i;
}
int find(int x)
{
    if(x==pre[x])
        return x;
    else
    {
        pre[x]=find(pre[x]);
        return pre[x];
    }
}
int mix(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        pre[fy]=fx;
        return 1;
    }
    return 0;
}
double dist(int x1,int y1,int x2,int y2)
{
    return sqrt((double)((x1-x2)*(x1-x2))+(double)((y1-y2)*(y1-y2)));
}
void Kruskal()
{
    sort(G,G+len,cmp);
    cnt=0;
    for(int i=0; i<len; i++)
    {
        if(mix(G[i].u,G[i].v))
        {
            zz[cnt].x=G[i].u;
            zz[cnt++].y=G[i].v;
        }
        if(cnt==n-1)
            break;

    }

}
int main()
{

    len=0;
    scanf("%d",&n);
    init();
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&zz[i].x,&zz[i].y);
        for(int j=1; j<i; j++)
        {
            G[len].u=i;
            G[len].v=j;
            G[len++].w=dist(zz[i].x,zz[i].y,zz[j].x,zz[j].y);
        }
    }
    int a,b;
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&a,&b);
        mix(a,b);
    }
    Kruskal();
    for(int i=0; i<cnt; i++)
        printf("%d %d\n",zz[i].x,zz[i].y);
    return 0;
}
