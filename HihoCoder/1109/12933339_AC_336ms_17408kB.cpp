#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=1e5+10;
const int M=1e6+10;
int pre[N],n,m;
struct edge
{
    int u,v,w;
} e[M];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
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
void kruskal()
{
    int cnt=0,sum=0;
    for(int i=1; i<=m; i++)
    {
        if(mix(e[i].u,e[i].v))
        {
            cnt++;
            sum+=e[i].w;
        }
        if(cnt==n-1)
            break;
    }
    printf("%d\n",sum);
}
int main()
{
    int u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    for(int i=1; i<=n; i++)
        pre[i]=i;
    sort(e+1,e+m+1,cmp);
    kruskal();
}
