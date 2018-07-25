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
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const int N=5000+20;
const int M=200000+20;
int top;
int h[N],pre[N],g[N];//h[i]记录每个节点的高度，pre[i]记录前驱,g[i]表示距离为i个节点数有多少个
int first[N];
struct node
{
    int v,next;
    int cap,flow;
} E[M*2];
void init()
{
    mem(first,-1);
    top=0;
}
void add_edge(int u,int v,int c)
{
    E[top].v=v;
    E[top].cap=c;
    E[top].flow=0;
    E[top].next=first[u];
    first[u]=top++;
}
void add(int u,int v,int c)
{
    add_edge(u,v,c);
    add_edge(v,u,0);
}

void set_h(int t)//标高函数,从终点向起点标高
{
    queue<int>q;
    mem(h,-1);
    mem(g,0);
    h[t]=0;
    q.push(t);
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        g[h[v]]++;//当前高度的个数+1
        for(int i=first[v]; ~i; i=E[i].next)
        {
            int u=E[i].v;
            if(h[u]==-1)//当前节点未标高
            {
                h[u]=h[v]+1;
                q.push(u);
            }
        }
    }
}

int Isap(int s,int t,int n)//isap算法
{
    set_h(t);
    int ans=0,u=s;
    int d;
    while(h[s]<n)//节点的高度小于顶点数
    {
        int i=first[u];
        if(u==s) d=inf;
        for(; ~i; i=E[i].next)
        {
            int v=E[i].v;
            if(E[i].cap>E[i].flow&&h[u]==h[v]+1)//容量大于流量且当前的高度等于要去的高度+1
            {
                u=v;
                pre[v]=i;
                d=min(d,E[i].cap-E[i].flow);//找最小增量
                if(u==t)//到达汇点
                {
                    while(u!=s)
                    {
                        int j=pre[u];//找到u的前驱
                        E[j].flow+=d;//正向流量+d
                        E[j^1].flow-=d;//反向流量-d
                        u=E[j^1].v;//向前搜索
                    }
                    ans+=d;
                    d=inf;
                }
                break;
            }
        }
        if(i==-1)//邻接边搜索完毕，无法行进
        {
            if(--g[h[u]]==0)//重要的优化，这个高度的节点只有一个,结束
                break;
            int hmin=n-1;//重贴标签的高度初始为最大
            for(int j=first[u]; ~j; j=E[j].next)
            {
                if(E[j].cap>E[j].flow)
                    hmin=min(hmin,h[E[j].v]);//取所有邻接点高度的最小值
            }
            h[u]=hmin+1;//重新标高
            g[h[u]]++;//标高后该高度的点数+1
            if(u!=s)//不是源点时，向前退一步，重新搜
                u=E[pre[u]^1].v;
        }
    }
    return ans;
}

//int main()
//{
//    int n,m,i,u,v,num;
//    while(scanf("%d%d",&n,&m)!=EOF)
//    {
//        R=0;                                    //将一个点拆成两个点从而将点权转换为边权
//        for(i=0; i<=2*n; i++)
//            tab[i].clear();
//        scanf("%d%d",&S,&T);
//        T+=n;
//        for(i=1; i<=n; i++)
//        {
//            scanf("%d",&num);
//            addedge(i,i+n,num);
//        }
//        for(i=0; i<m; i++)                      //相当于连成一个圈，但不是两个点直接相连
//        {
//            scanf("%d%d",&u,&v);
//            addedge(u+n,v,INF);
//            addedge(v+n,u,INF);
//        }
//        printf("%d\n",dinic());
//    }
//    return 0;
//}

int main()
{
    int n,m,st,ed,u,v,x;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        scanf("%d%d",&st,&ed);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            add(2*i-1,2*i,x);
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            add(2*u,2*v-1,inf);
            add(2*v,2*u-1,inf);
        }
        printf("%d\n",Isap(st*2-1,ed*2,2*n));
    }
    return 0;
}
