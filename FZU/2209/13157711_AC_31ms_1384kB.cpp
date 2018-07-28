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
//const int N=1000+7;
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
//
//void init()
//{
//    tot=0;
//    mem(first,-1);
//    mem(d,0);
//    mem(p,0);
//}
//int main()
//{
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
//        for(int i=1; i<=m; i++)
//        {
//            scanf("%d%d%d",&u,&v,&k);
//            dfs(1,0);
//            int ans=lca(u,v);
//            int z=dis[u]-dis[ans]+1;
//            int y=dis[v]-dis[ans]+1;
//            if(k==z)
//            {
//                printf("%d\n",ans);
//            }
//            else if(k<z)
//            {
//            }
//            else if(k>z)
//            {
//                k-=z;
//
//            }
//        }
//    }
//    return 0;
//}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=110;
int t,n,m,k,dis[maxn],sss,st,minn,book[maxn];
struct node
{
    int v,w[30];
} tem;
vector <node> vec[maxn];
void init()
{
    for(int i=1; i<=n; i++)
        dis[i]=inf;
    dis[1]=0;
    for(int i=1; i<=n; i++) book[i]=0;
}
void dijkstra()
{
    int u;
    for(int i=1; i<=n; i++)
    {
        minn=inf;
        for(int j=1; j<=n; j++)
        {
            if(!book[j]&&dis[j]<minn)
            {
                minn=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(int j=0; j<vec[u].size(); j++)
        {
            if(dis[vec[u][j].v]>dis[u]+vec[u][j].w[(dis[u]+sss)%24])
                dis[vec[u][j].v]=dis[u]+vec[u][j].w[(dis[u]+sss)%24];
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int cas=0,ans[maxn];
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        int u;
        scanf("%d%d%d",&n,&m,&k);
        memset(vec,0,sizeof(vec));
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&tem.v);
            for(int j=0; j<24; j++)
                scanf("%d",&tem.w[j]);
            vec[u].push_back(tem);
            swap(tem.v,u);
            vec[u].push_back(tem);
        }
        for(int i=1; i<=k; i++)
        {
            scanf("%d%d",&st,&sss);
            init();
            dijkstra();
            if(dis[st]!=inf)
                ans[i]=dis[st];
            else
                ans[i]=-1;
        }
        printf("Case #%d:",cas);;
        for(int i=1; i<=k; i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}