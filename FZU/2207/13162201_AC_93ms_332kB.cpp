//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <stdlib.h>
//#include <string>
//#include <map>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//#define inf 1000000
//#define mem(a,b) memset(a,b,sizeof(a))
//const int N=2000+7;
//
//int n,m,s;
//int tot;
//int first[N],d[N],p[N][21];
//
//struct edge
//{
//    int v,next;
//} e[2*N];
//
//void add_edge(int u,int v)
//{
//    e[tot].v=v;
//    e[tot].next=first[u];
//    first[u]=tot++;
//}
//
//void dfs(int u,int fa)
//{
//    d[u]=d[fa]+1;
//    p[u][0]=fa;
//    for(int i=1; (1<<i)<=d[u]; i++)
//        p[u][i]=p[p[u][i-1]][i-1];
//    for(int i=first[u]; ~i; i=e[i].next)
//    {
//        int v=e[i].v;
//        if(v!=fa)
//            dfs(v,u);
//    }
//}
//
//int lca(int a,int b)
//{
//    if(d[a]>d[b]) swap(a,b);//保证a在b点的上方
//    for(int i=20; i>=0; i--)
//        if(d[a]<=d[b]-(1<<i))
//            b=p[b][i];  //把b移到和a同一个深度
//    if(a==b) return a;
//    for(int i=20; i>=0; i--)
//    {
//        if(p[a][i]==p[b][i])
//            continue;
//        else
//            a=p[a][i],b=p[b][i];//一起向上跳跃
//    }
//    return p[a][0];
//}
//
//void init()
//{
//    tot=0;
//    mem(first,-1);
//    mem(d,0);
//    mem(p,0);
//}
//int calc(int ans,int x)
//{
//    for(int i=0; (1<<i)<=x; i++)
//    {
//        if(x&(1<<i))
//            ans=p[ans][i];
//    }
//    return ans;
//}
//int main()
//{
//    //freopen("in.txt","r",stdin);
//    int t,u,v,k,q=1;
//    scanf("%d",&t);
//    while(t--)
//    {
//        init();
//        scanf("%d%d",&n,&m);
//        for(int i=1; i<n; i++)
//        {
//            scanf("%d%d",&u,&v);
//            add_edge(u,v);
//            add_edge(v,u);
//        }
//        printf("Case #%d:\n",q++);
//        dfs(1,0);
//        for(int i=1; i<=m; i++)
//        {
//            scanf("%d%d%d",&u,&v,&k);
//
//            int root=lca(u,v);
//            int z=d[u]-d[root]+1;
//            int y=d[v]-d[root]+1;
//            if(k==z)
//            {
//                printf("%d\n",root);
//            }
//            else if(k<z)
//            {
//                int ans=u;//跳k-1步
//                printf("%d\n",calc(ans,k-1));
//            }
//            else if(k>z)
//            {
//                k=k-z+1;
//                k=y-k+1;//跳k步
//                int ans=v;
//                printf("%d\n",calc(ans,k-1));
//            }
//        }
//    }
//    return 0;
//}
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1000+7;

int n,m,s;
int tot;
int first[N],d[N],p[N][21];

struct edge
{
    int v,next;
} e[2*N];

void add_edge(int u,int v)
{
    e[tot].v=v;
    e[tot].next=first[u];
    first[u]=tot++;
}

void dfs(int u,int fa)
{
    d[u]=d[fa]+1;
    p[u][0]=fa;
    for(int i=1; (1<<i)<=d[u]; i++)
        p[u][i]=p[p[u][i-1]][i-1];
    for(int i=first[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(v!=fa)
            dfs(v,u);
    }
}

int lca(int a,int b)
{
    if(d[a]>d[b]) swap(a,b);//保证a在b点的上方
    for(int i=20; i>=0; i--)
        if(d[a]<=d[b]-(1<<i))
            b=p[b][i];  //把b移到和a同一个深度
    if(a==b) return a;
    for(int i=20; i>=0; i--)
    {
        if(p[a][i]==p[b][i])
            continue;
        else
            a=p[a][i],b=p[b][i];//一起向上跳跃
    }
    return p[a][0];
}


void init()
{
    tot=0;
    mem(first,-1);
    mem(d,0);
    mem(p,0);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t,u,v,k,q=1;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        printf("Case #%d:\n",q++);
         dfs(1,0);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&k);
           
            int root=lca(u,v);
            int z=d[u]-d[root]+1;
            int y=d[v]-d[root]+1;
            if(k==z)
            {
                printf("%d\n",root);
            }
            else if(k<z)
            {
                int ans=u;
                for(int i=1; i<k; i++)
                {
                    ans=p[ans][0];
                }
                printf("%d\n",ans);
            }
            else if(k>z)
            {
                k-=z;
                k=y-k;
                int ans=v;
                for(int i=1; i<k; i++)
                {
                    ans=p[ans][0];
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}