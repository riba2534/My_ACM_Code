 
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
int t,n;
int num[1000000+50];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int maxx=-inf,sum=0;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%d",&num[i]);
		for(int i=0; i<n; i++)
		{
			sum+=num[i];
			maxx=max(maxx,sum);
			if(sum<0)
				sum=0;
		}
		printf("%d\n",maxx);
	}
	return 0;
}
        