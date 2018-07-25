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
const int N=200+20;
const int M=N*N;
int top;
int h[N],pre[N],g[N];//h[i]记录每个节点的高度，pre[i]记录前驱,g[i]表示距离为i个节点数有多少个
int first[N];
bool vis[N];
struct node
{
    int v,next;
    int cap,flow;
} E[M];
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


inline int read()
{
    char ch=getchar();
    int x=0,f=1;
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}


int fa[N];//并查集的前驱
int find(int x)
{
    if(x==fa[x])
        return x;
    else
    {
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
void mix(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
        fa[fy]=fx;
}
bool flag[N][N];
int solve(int k,int n)
{
    init();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            if(flag[i][j])
                add(i,j+n,1);
        add(0,i,k);
        add(n+i,2*n+1,k);
    }
    return Isap(0,2*n+1,2*n+2)==n*k;
}

int main()
{
    int t,f,a,b,n,m;
    // scanf("%d",&t);
    t=read();
    while(t--)
    {
        //scanf("%d%d%d",&n,&m,&f);
        n=read();
        m=read();
        f=read();
        for(int i=1; i<=n; i++)
            fa[i]=i;
        mem(flag,0);
        for(int i=1; i<=m; i++)
        {
            a=read();
            b=read();
            //scanf("%d%d",&a,&b);
            flag[a][b]=true;
        }
        for(int i=1; i<=f; i++)
        {
            //scanf("%d%d",&a,&b);
            a=read();
            b=read();
            mix(a,b);//是朋友的女生加入到同一个并查集中
        }
        for(int i=1; i<=n; i++)
        {
            int x=find(i);
            for(int j=1; j<=n; j++)
            {
                if(flag[i][j]&&!flag[x][j])
                    flag[x][j]=1;
            }
        }
        for(int i=1; i<=n; i++)
        {
            int x=find(i);
            for(int j=1; j<=n; j++)
            {
                if(!flag[i][j]&&flag[x][j])
                    flag[i][j]=1;
            }
        }
        int l=0,r=n,ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(solve(mid,n))
            {
                l=mid+1;
                ans=mid;
            }
            else
                r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
