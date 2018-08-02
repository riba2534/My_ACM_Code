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
//#define N 300
//#define ll long long
//using namespace std;
//int main()
//{
//
//  return 0;
//}
//
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
const LL N=100005;
const LL inf=10000000000;
LL n;
LL L,R;
LL sum[N];
struct node
{
	LL l,r,cnt;
} dt[N*35];
LL cnt_node=1;
void insert(LL &rt,LL l,LL r,LL val)
{
	if(!rt)
		rt=++cnt_node;
	++dt[rt].cnt;
	if(l==r)
		return;
	LL m=(l+r)>>1;
	if(val<=m)
		insert(dt[rt].l,l,m,val);
	else
		insert(dt[rt].r,m+1,r,val);
}
LL query(LL rt,LL l,LL r,LL x,LL y)
{
	if(x<=l&&y>=r)
		return dt[rt].cnt;
	LL m=(l+r)>>1;
	LL tmp=0;
	if(x<=m&&dt[rt].l)
		tmp+=query(dt[rt].l,l,m,x,y);
	if(y>m&&dt[rt].r)
		tmp+=query(dt[rt].r,m+1,r,x,y);
	return tmp;
}
int main()
{
	scanf("%lld%lld%lld",&n,&L,&R);
	for(LL i=1; i<=n; i++)
	{
		scanf("%lld",&sum[i]);
		sum[i]+=sum[i-1];
	}
	LL ans=0;
	LL rt=1;
	insert(rt,-inf,inf,0);
	//先插入0
	for(LL i=1; i<=n; i++)
	{
		//每次寻找sum[i]-R,sum[i]-ll区间存在的数量.
		ans+=query(rt,-inf,inf,sum[i]-R,sum[i]-L);
		//记录后插入该区间
		insert(rt,-inf,inf,sum[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
