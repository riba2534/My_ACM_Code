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
#define N 60050
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int MAX[N<<2],MIN[N<<2];
void pushup(int rt)
{
	MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
	MIN[rt]=min(MIN[rt<<1],MIN[rt<<1|1]);
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%d",&MAX[rt]);
		MIN[rt]=MAX[rt];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(rt);
}
int query1(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		return MAX[rt];
	}
	int m=(l+r)>>1;
	int ret=0;
	if(L<=m) ret=max(ret,query1(L,R,lson));
	if(m<R) ret=max(ret,query1(L,R,rson));
	return ret;
}

int query2(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		return MIN[rt];
	}
	int m=(l+r)>>1;
	int ret=inf;
	if(L<=m) ret=min(ret,query2(L,R,lson));
	if(m<R) ret=min(ret,query2(L,R,rson));
	return ret;
}
int main()
{
	int n,q,a,b;
	while(~scanf("%d%d",&n,&q))
	{
		mem(MAX,0);
		build(1,n,1);
		while(q--)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",query1(a,b,1,n,1)-query2(a,b,1,n,1));
		}
	}
	return 0;
}
