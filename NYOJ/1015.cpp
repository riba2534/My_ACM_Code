 
//#include <bits/stdc++.h>
//using namespace std;
//#define mem(a,b) memset(a,b,sizeof(a))
//const int N=1e4+10;
//const int M=4e4+10;
//int first[N],tot,vis[N];
//int n,m;
//struct node
//{
//    int v,next;
//} e[2*M];
//void add_edge(int u,int v)
//{
//    e[tot].v=v;
//    e[tot].next=first[u];
//    first[u]=tot++;
//}
//void init()
//{
//    mem(first,-1);
//    mem(vis,-1);
//    tot=0;
//}
//int bfs()
//{
//    queue<int>q;
//    q.push(1);
//    vis[1]=1;
//    while(!q.empty())
//    {
//        int u=q.front();
//        q.pop();
//        for(int i=first[u]; ~i; i=e[i].next)
//        {
//            int v=e[i].v;
//            if(vis[v]==-1)
//            {
//                vis[v]=-vis[u];
//                q.push(v);
//            }
//            else if(vis[u]==vis[v])
//                return 0;
//        }
//    }
//    return 1;
//}
//int main()
//{
//    int t,u,v;
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d%d",&n,&m);
//        init();
//        for(int i=1; i<=m; i++)
//        {
//            scanf("%d%d",&u,&v);
//            add_edge(u,v);
//            add_edge(v,u);
//        }
//        if(bfs()) puts("Correct");
//        else puts("Wrong");
//    }
//    return 0;
//}
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define ll longlong
using namespace std;
const int N=200+20;
vector<int> G[N];
int color[N];
int dfs()
{
    queue<int>q;
    q.push(0);
    color[0]=1;
    while(!q.empty())
    {
        int v1=q.front();
        q.pop();
        for(int i=0; i<G[v1].size(); i++)
        {
            int v2=G[v1][i];
            if(!color[v2])
            {
                color[v2]=-color[v1];
                q.push(v2);
            }
            else if(color[v1]==color[v2])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int n,m,a,b;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<N; i++)G[i].clear();
        mem(color,0);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(dfs())
            puts("BICOLORABLE.");
        else
            puts("NOT BICOLORABLE.");
    }
    return 0;
}
        