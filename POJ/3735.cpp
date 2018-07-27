#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const ll N=105;
struct Matrix
{
	ll a[N][N];
	Matrix()
	{
		mem(a,0);
	}
	void init()
	{
		mem(a,0);
		for(ll i=0; i<N; i++)
			a[i][i]=1;
	}
};
void print(Matrix a)
{
	for(ll i=0; i<N; i++)
	{
		for(ll j=0; j<N; j++)
			printf("%d ",a.a[i][j]);
		puts("");
	}
}
Matrix mul(Matrix a,Matrix b)
{
	Matrix ans;
	for(ll i=0; i<N; i++)
		for(ll j=0; j<N; j++)
			if(a.a[i][j])
				for(ll k=0; k<N; k++)
					ans.a[i][k]+=a.a[i][j]*b.a[j][k];
	return ans;
}
Matrix mat_pow(Matrix a,ll n)
{
	Matrix ans;
	ans.init();
	while(n)
	{
		if(n&1)
			ans=mul(ans,a);
		a=mul(a,a);
		n>>=1;
	}
	return ans;
}
int main()
{
	ll n,m,k,x,y;
	char s[5];
	while(scanf("%lld%lld%lld",&n,&m,&k)&&n)
	{
		Matrix p;
		p.init();
		while(k--)
		{
			scanf("%s%lld",s,&x);
			if(s[0]=='g')
				p.a[0][x]++;
			else if(s[0]=='e')
				for(int i=0; i<=n; i++)
					p.a[i][x]=0;
			else if(s[0]=='s')
			{
				scanf("%lld",&y);
				for(int i=0; i<=n; i++)
					swap(p.a[i][x],p.a[i][y]);
			}
		}
		Matrix B=mat_pow(p,m);
		Matrix A;
		A.a[0][0]=1;
		Matrix ans=mul(A,B);
		for(ll i=1; i<=n; i++)
		{
			if(i>1)printf(" ");
			printf("%lld",ans.a[0][i]);
		}
		puts("");
	}
	return 0;
}
