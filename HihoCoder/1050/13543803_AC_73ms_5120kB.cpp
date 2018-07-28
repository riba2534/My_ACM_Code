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
const int N=1e5+20;
int n;
int first[N],tot,maxdepth,root;
struct edge
{
    int v,next;
} e[N*2];
void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}
void init()
{
    mem(first,-1);
    tot=0;
    maxdepth=0;
    root=0;
}
void dfs(int depth,int u,int fa)
{
    if(depth>maxdepth)
    {
        maxdepth=depth;
        root=u;
    }
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v!=fa)
            dfs(depth+1,v,u);
    }
}

int main()
{
    int u,v;
    init();
    scanf("%d",&n);
    for(int i=1; i<=n-1; i++)
    {
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(0,1,0);
    maxdepth=0;
    dfs(0,root,0);
    printf("%d\n",maxdepth);
    return 0;
}

