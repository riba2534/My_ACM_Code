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
#define N 100005
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct node
{
	int see;
	double angle;
} t[N<<2];
int query(int l,int r,int rt,double val)
{
	if(l==r) return val<t[rt].angle;
	int m=(l+r)>>1;
	if(val>=t[rt<<1].angle)
		return query(rson,val);
	return t[rt].see-t[rt<<1].see+query(lson,val);
}
void update(int p,int l,int r,int rt,double val)
{
	if(l==r)
	{
		t[rt].see=1;
		t[rt].angle=val;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m)
		update(p,lson,val);
	else
		update(p,rson,val);
	t[rt].angle=max(t[rt<<1].angle,t[rt<<1|1].angle);
	t[rt].see=t[rt<<1].see+query(rson,t[rt<<1].angle);
}
int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		update(x,1,n,1,y*1.0/x);
		printf("%d\n",t[1].see);
	}
	return 0;
}
