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
const int N=1000+20;
const int M=N*N;
int top;
int h[N],pre[N],g[N];//h[i]记录每个节点的高度，pre[i]记录前驱,g[i]表示距离为i个节点数有多少个
int first[N];
bool vis[N];
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

char s[N];
struct point
{
    int x,y,flow;//横纵坐标和柱子告诉
    bool flag;//是否有蜥蜴
} p[N];
bool judge_line(point a, point b, int d)
{
    int len = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    if(d*d >= len)
        return true;
    else
        return false;
}
int main()
{
    int t,q=1,n,d,m,st,ed;
    scanf("%d",&t);
    while(t--)
    {
        int k=0;
        init();
        scanf("%d%d",&n,&d);
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            m=strlen(s);
            for(int j=0; j<m; j++)
            {
                k++;
                p[k].x=i;
                p[k].y=j;
                p[k].flow=s[j]-'0';
            }
        }
        k=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            for(int j=0; j<m; j++)
            {
                k++;
                if(s[j]=='L')
                    p[k].flag=true;
                else
                    p[k].flag=false;
            }
        }
        st=2*k+1,ed=st+1;
        int sum=0;
        for(int i=1; i<=k; i++)
        {
            if(p[i].flow)//如果柱子高度大于0
            {
                add(i,i+k,p[i].flow);
                // add(2*i-1,2*i,p[k].flow);//给柱子拆点
                if(p[i].x-d<0||p[i].x+d>=n||p[i].y-d<0||p[i].y+d>=m)//如果可以直接跳出，柱子与汇点相连
                    //add(2*i,ed,inf);
                    add(i+k,ed,inf);
                if(p[i].flag)//如果是蜥蜴，源点和柱子左边相连
                {
                    // add(0,2*i-1,1);
                    add(st,i,1);
                    sum++;
                }
                for(int j=1; j<=k; j++)
                {
                    if(i==j)continue;
                    if(p[j].flow&&judge_line(p[i],p[j],d))
                        //add(2*i,2*j-1,inf);
                        add(i+k,j,inf);
                }
            }
        }
        int ans=sum-Isap(st,ed,2*k+3);
        if(ans == 0)
            printf("Case #%d: no lizard was left behind.\n", q++);
        else if(ans == 1)
            printf("Case #%d: 1 lizard was left behind.\n", q++);
        else
            printf("Case #%d: %d lizards were left behind.\n", q++, ans);
    }
    return 0;
}
