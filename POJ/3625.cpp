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
#define N 2000000+20
#define M 200010
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
int n,m,num;
int pre[N];
struct node
{
    int u,v;
    double w;
} G[N];
struct md
{
    double x,y;
} zz[N];
double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool cmp(node a,node b)
{
    return a.w<b.w;
}
void init(int n)
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
void Kruskal()
{
    int cnt=0;
    double sum=0;
    for(int i=0; i<num; i++)
    {
        if(mix(G[i].u,G[i].v))
        {
            cnt++;
            sum+=G[i].w;
        }
    }
    if(cnt==n-1)//进行n-1次就可以了
    {
        printf("%.2f\n",sum);
        return;
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        num=0;
        init(n);
        for(int i=1; i<=n; i++)
            scanf("%lf%lf",&zz[i].x,&zz[i].y);
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                G[num].u=i;
                G[num].v=j;
                G[num++].w=dist(zz[i].x,zz[i].y,zz[j].x,zz[j].y);
                G[num].u=j;
                G[num].v=i;
                G[num++].w=dist(zz[i].x,zz[i].y,zz[j].x,zz[j].y);
            }
        }
        int a,b;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&a,&b);
            G[num].u=a;
            G[num].v=b;
            G[num++].w=0;
            G[num].u=b;
            G[num].v=a;
            G[num++].w=0;
        }
        sort(G,G+num,cmp);
        Kruskal();
    }
    return 0;
}
