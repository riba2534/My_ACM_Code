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
#define N 20200
#define M 12357
#define ll long long
using namespace std;
int a[N],b[N];
int main()
{
	int t,n,q=1;
	scanf("%d",&t);
	while(t--)
	{
		mem(a,0);mem(b,0);
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0; i<n; i++)
		{
			scanf("%d",&b[i]);
		}
		int sum=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]+b[i]>10)
				sum++;
		}
		
		
		printf("Case %d: %d\n",q++,sum);


	}
	return 0;
}