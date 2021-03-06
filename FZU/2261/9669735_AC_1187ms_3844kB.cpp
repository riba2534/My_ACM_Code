//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <string>
//#include <set>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define mod 1000007
//#define N 101000
//#define M 12357
//#define ll long long
//using namespace std;
//int n,m;
//int first[N],len,vis[N],dis[N],s[N],e[N];
//struct node
//{
//	int u,v,w,next;
//} G[N];
//struct node2
//{
//	int num,cost;
//	bool friend operator < (node x,node y)
//	{
//		return x.cost>y.cost;
//	}
//};
//void add_edge(int u,int v,int w)
//{
//	G[len].v=v,G[len].w=w;
//	G[len].next=first[u];
//	first[u]=len++;
//}
//void spfa(int st)
//{
//
//	for(int i=1; i<=n; i++)
//	{
//		dis[i]=inf;
//		vis[i]=0;
//	}
//	node2 a,b;
//	priority_queue<node2>q;
//	int S,x;
//	scanf("%d",&S);
//	for(int i=1;i<=S;i++)
//	{
//		scanf("%d",&x);
//		dis[x]=0;
//		a.num=x;
//		a.cost=0;
//		q.push(a);
//		vis[x]=1;
//	}
//	while(!q.empty())
//	{
//		a=q.top();
//		q.pop();
//	}
//
//
//
//
//	dis[st]=0;
//	vis[st]=1;
//
//	queue<int>q;
//	q.push(st);
//	while(!q.empty())
//	{
//		st=q.front();
//		q.pop();
//		vis[st]=0;
//		for(int i=first[st]; i!=-1; i=G[i].next)
//		{
//			int v=G[i].v,w=G[i].w;
//			if(dis[v]>dis[st]+w)
//			{
//				dis[v]=dis[st]+w;
//				if(!vis[v])
//				{
//					vis[v]=1;
//					q.push(v);
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	while(~scanf("%d%d",&n,&m))
//	{
//		int a,b,c;
//		int minn=inf;
//		len=1;
//		for(int i=1; i<=m; i++)
//		{
//			scanf("%d%d%d",&a,&b,&c);
//			add_edge(a,b,c);
//		}
//		spfa();
//
//
//	}
//	return 0;
//}
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 1000007
#define N 101000
#define M 12357
#define ll long long
using namespace std;
int n,m,a,b,c;
int first[N],len,vis[N],dis[N],s[N],e[N];
struct node
{
	int u,v,w,next;
} G[N];
void add_edge(int u,int v,int w)
{
	G[len].v=v,G[len].w=w;
	G[len].next=first[u];
	first[u]=len++;
}
void spfa(int st)
{
	for(int i=1; i<=n; i++)
	{
		dis[i]=inf;
		vis[i]=0;
	}
	dis[st]=0;
	vis[st]=1;

	queue<int>q;
	q.push(st);
	while(!q.empty())
	{
		//puts("dddddddddddd");
		st=q.front();
		q.pop();
		vis[st]=0;
		for(int i=first[st]; i!=-1; i=G[i].next)
		{
			int v=G[i].v,w=G[i].w;
			//printf("v=%d,w=%d\n",v,w);
			if(dis[v]>dis[st]+w)
			{
				dis[v]=dis[st]+w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		int minn=inf;
		len=1;
		mem(first,-1);
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			add_edge(a,b,c);
		}
		int x,y;
		scanf("%d",&x);
		for(int i=1; i<=x; i++)
			scanf("%d",&s[i]);
		scanf("%d",&y);
		for(int i=1; i<=y; i++)
			scanf("%d",&e[i]);
		for(int i=1; i<=x; i++)
		{

			spfa(s[i]);
			for(int j=1; j<=y; j++)
			{
				//printf("s[i]=%d,dis[%d]=%d\n",s[i],e[j],dis[e[j]]);
				minn=min(minn,dis[e[j]]);
			}
		}
		printf("%d\n",minn);
	}
	return 0;
}
