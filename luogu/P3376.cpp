#include <bits/stdc++.h>

using namespace std;
const int INF=1<<27;
int n,m,s,t;

int read()
{
	char ch;int num,f=0;
	while(!isdigit(ch=getchar())) f|=(ch=='-');
	num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return f?-num:num;
}

struct edge
{
	int to,cap,rev;
};
vector<edge> a[10005];
bool vis[10005];

void add_edge(int x,int y,int c)
{
	a[x].push_back(edge{y,c,a[y].size()});
	a[y].push_back(edge{x,0,a[x].size()-1});
}

int dfs(int v,int t,int f)
{
	if(v==t) return f;
	int ret=0;vis[v]=true;
	for(int i=0;i<a[v].size();i++)
	{
		edge &e=a[v][i];
		if(!vis[e.to] && e.cap>0)
		{
			int d=dfs(e.to,t,min(f,e.cap));
			e.cap-=d;a[e.to][e.rev].cap+=d;f-=d;ret+=d;
		}
	}
	return ret;
}

int main()
{
	n=read();m=read();s=read();t=read();
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		x=read();y=read();c=read();
		add_edge(x,y,c);
	}
	
	int res=dfs(s,t,INF);
	cout << res;
	return 0;
}