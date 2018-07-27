#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const ll N=2;
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
			for(ll k=0; k<N; k++)
			{
				ans.a[i][j]+=a.a[i][k]*b.a[k][j];
				ans.a[i][j]%=mod;
			}
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
	ll n;
	while(scanf("%lld",&n)&&n!=-1)
	{
		if(n==0)
			puts("0");
		else if(n==1)
			puts("1");
		else
		{
			Matrix A;
			A.a[0][0]=A.a[0][1]=A.a[1][0]=1;
			A.a[1][1]=0;
			Matrix p=mat_pow(A,n-1);
			Matrix B;
			B.a[0][0]=1;
			Matrix ans=mul(B,p);
			printf("%lld\n",ans.a[0][0]);
		}
	}
	return 0;
}