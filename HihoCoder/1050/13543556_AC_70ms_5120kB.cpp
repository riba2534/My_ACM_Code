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
int first[N],tot,ans;
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
    ans=0;
}
int dfs(int u,int fa)
{
    int fir=0,sec=0,depth;
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v!=fa)
        {
            depth=dfs(v,u)+1;
            if(depth>fir)
            {
                sec=fir;
                fir=depth;
            }
            else if(depth>sec)
                sec=depth;
        }
    }
    ans=max(ans,fir+sec);
    return fir;
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
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}
