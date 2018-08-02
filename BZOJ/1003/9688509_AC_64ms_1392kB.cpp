#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=25;
typedef long long ll;
int n,m,k,E,D,tot;
int first[N],dis[N];;
bool flag[N][105];
ll t[105][105],f[105];
struct node
{
	int u,v,w,next;
} e[N*N];
void add_edge(int u,int v,int w)
{
	e[tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].next=first[u];
	first[u]=tot++;
}
ll spfa(int x,int y)
{
	bool book[N],vis[N];
	mem(dis,inf);
	mem(book,false);
	mem(vis,false);
	for(int i=1; i<=m; i++)
	{
		for(int j=x; j<=y; j++)
		{
			if(flag[i][j])book[i]=true;//x~y这个时间段内i不能访问
		}
	}
	queue<int>q;
	q.push(1);
	dis[1]=0,vis[1]=true;
	while(!q.empty())
	{
		int st=q.front();
		q.pop();
		vis[st]=0;
		for(int i=first[st]; ~i; i=e[i].next)
		{
			if(!book[e[i].v]&&dis[e[i].v]>dis[st]+e[i].w)
			{
				dis[e[i].v]=dis[st]+e[i].w;
				if(!vis[e[i].v])
				{
					vis[e[i].v]=1;
					q.push(e[i].v);
				}
			}
		}
	}
	return dis[m];
}
void solve()
{
	for(int i=1; i<=n; i++)
	{
		f[i]=t[1][i]*i;//1~i天全用一条线路
		for(int j=0; j<i; j++)
		{
			f[i]=min(f[i],f[j]+t[j+1][i]*(i-j)+k);//改变线路的情况
		}
	}
}
int main()
{
	tot=0;
	mem(first,-1);
	mem(flag,false);
	scanf("%d%d%d%d",&n,&m,&k,&E);
	int u,v,w,D,l,r,x;
	for(int i=0; i<E; i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	scanf("%d",&D);
	for(int i=0; i<D; i++)
	{
		scanf("%d%d%d",&x,&l,&r);
		for(int j=l; j<=r; j++)
		{
			flag[x][j]=1;//标记x点在l~r这段时间不能用
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++)
			t[i][j]=spfa(i,j);//满足i~j时间1~m的最小距离
	solve();
	printf("%lld\n",f[n]);
}
