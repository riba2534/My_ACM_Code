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
const int N=5000+120;
const int M=50000+5;

int top;//��ǰ���±�
int dis[N],pre[N];//Դ�㵽��i����С���룬pre[i]��¼ǰ��
bool vis[N];//�������
int maxflow;
int first[N];//�洢ͷ���
struct Edge
{
    int v,next;
    int cap,flow,cost;
} E[M*2];

void init()
{
    mem(first,-1);
    top=0;
    maxflow=0;
}

void add_edge(int u,int v,int c,int cost)
{
    E[top].v=v;
    E[top].cap=c;
    E[top].flow=0;
    E[top].cost=cost;
    E[top].next=first[u];
    first[u]=top++;
}
void add(int u,int v,int c,int cost)
{
    add_edge(u,v,c,cost);
    add_edge(v,u,0,-cost);
}
bool spfa(int s,int t)
{
    int i,u,v;
    queue<int>q;
    mem(vis,false);
    mem(pre,-1);
    mem(dis,inf);
    vis[s]=true;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=first[u]; i!=-1; i=E[i].next)
        {
            v=E[i].v;
            if(E[i].cap>E[i].flow&&dis[v]>dis[u]+E[i].cost)
            {
                dis[v]=dis[u]+E[i].cost;
                pre[v]=i;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    if(dis[t]==inf)
        return false;
    return true;
}
int MCMF(int s,int t)//minCostMaxFlow
{
    int d;
    int i,mincost=0;//maxflow��ǰ���������mincost��ǰ��С����
    while(spfa(s,t))//��ʾ�ҵ��˴�s��t����С����·
    {
        d=inf;
        for(int i=pre[t]; i!=-1; i=pre[E[i^1].v]) //���������
            d=min(d,E[i].cap-E[i].flow);
        maxflow+=d;//���������
        for(int i=pre[t]; i!=-1; i=pre[E[i^1].v]) //����·�����������+d,���������-d
        {
            E[i].flow+=d;
            E[i^1].flow-=d;
        }
        mincost+=dis[t]*d;//dis[t]Ϊ��·���ϵ�λ��������֮��
    }
    return mincost;
}
int a[N][N],b[N][N],c[N];
/*
a[i][j]�洢��i��������Ҫ��j�ֻ���ĸ���
b[i][j]�洢��i�������ص��j�ֻ����ʣ����
c[i][j]�洢��j�������̰ѵ�ǰ�Ļ������͵���i�������Ļ���
*/
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,k,x;
    while(scanf("%d%d%d",&n,&m,&k)&&(n||m||k))
    {
        mem(c,0);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=k; j++)
            {
                scanf("%d",&a[i][j]);
                c[j]+=a[i][j];
            }
        for(int i=1; i<=m; i++)
            for(int j=1; j<=k; j++)
                scanf("%d",&b[i][j]);
        int ans=0,flag=1;
        for(int o=1; o<=k; o++)//��o����Ʒ
        {
            init();
            for(int i=1; i<=n; i++)//��i������
                for(int j=1; j<=m; j++)//��j��������
                {
                    scanf("%d",&x);
                    add(j,m+i,b[j][o],x);
                }
                if(flag==0)
                continue;
            for(int i=1; i<=m; i++)
                add(0,i,b[i][o],0);//��Դ�㵽��i���ֿ�������ǲֿ�ĵ�ǰ��Ʒ�Ĵ������������0
            for(int i=1; i<=n; i++)
                add(m+i,m+n+1,a[i][o],0);//�ӵ�������ǰ����Ҫ����Ʒ(���)�������ǵ������������Ʒ����������������0
            int now=MCMF(0,m+n+1);
            if(maxflow!=c[o])
            {
                flag=0;
                continue;
            }
            else
                ans+=now;
        }
        if(flag)
            printf("%d\n",ans);
        else
            puts("-1");
    }
    return 0;
}
