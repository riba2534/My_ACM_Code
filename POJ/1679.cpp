#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=100+10;
const int M=N*N;
int pre[N],n,m,vis[M];
struct edge
{
    int u,v,w;
} e[M];
vector<int>v;
vector<int>p;
void init()
{
    for(int i=1; i<=n; i++)
        pre[i]=i;
}
int find(int x)
{
    return x==pre[x]?x:pre[x]=find(pre[x]);
}
int mix(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
    {
        pre[fy]=fx;
        return 1;
    }
    return 0;
}
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int kruskal(int flag)
{
    init();
    int sum=0,cnt=0;
    for(int i=1; i<=m; i++)
    {
        if(vis[i])continue;
        if(mix(e[i].u,e[i].v))
        {
            if(flag)
                v.push_back(i);
            cnt++;
            sum+=e[i].w;
        }
        if(cnt==n-1)
            break;
    }
    if(cnt==n-1)
        return sum;
    return inf;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        p.clear();
        mem(vis,0);
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sort(e+1,e+m+1,cmp);
        int ans=kruskal(1);
        for(int i=0; i<v.size(); i++)
        {
            vis[v[i]]=1;
            p.push_back(kruskal(0));
            vis[v[i]]=0;
        }
        sort(p.begin(),p.end());
        if(ans==p[0])
            puts("Not Unique!");
        else
            printf("%d\n",ans);
    }
    return 0;
}
