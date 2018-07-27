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
#define N 10050
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[N<<2],num[N],tot;
void pushdown(int rt)
{
	if(sum[rt]!=-1)
	{
		sum[rt<<1]=sum[rt<<1|1]=sum[rt];
		sum[rt]=-1;
	}
}
void update(int L,int R,int c,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		sum[rt]=c;
		return;
	}
	pushdown(rt);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,c,lson);
	if(m<R) update(L,R,c,rson);
}
void query(int l,int r,int rt)
{
	if(l==r)
	{
		if(sum[rt]>=0&&sum[rt]!=tot)
			num[sum[rt]]++;
		tot=sum[rt];
		return;
	}
	pushdown(rt);
	int m=(l+r)>>1;
	query(lson);
	query(rson);
}
int main()
{
	int n,a,b,c;
	while(~scanf("%d",&n))
	{
		mem(num,0);
		mem(sum,-1);
		tot=-1;
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			
				update(a+1,b,c,1,8000,1);
		}
		query(1,8000,1);
		for(int i=0; i<=8000; i++)
			if(num[i])
				printf("%d %d\n",i,num[i]);
		puts("");
	}
	return 0;
}