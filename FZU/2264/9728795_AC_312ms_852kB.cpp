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
#define N 80000
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
		mem(a,0);
		mem(b,0);
		scanf("%d",&n);
		for(int i=0; i<2*n; i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+2*n);
		int cnt=0;
		for(int i=2*n-1; i>=0; i--)
		{
			if(a[i]==a[i-1])
				continue;
			else
				cnt++;
		}
		printf("Case %d: %.2lf\n",q++,cnt*1.0/4);
	}
	return 0;
}
