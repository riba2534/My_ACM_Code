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
#define N 10000+20
#define ll long long
using namespace std;
int a[N];
int main()
{
	int n,k=1,q,x;
	while(~scanf("%d%d",&n,&q)&&(n||q))
	{
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("CASE# %d:\n",k++);
		while(q--)
		{
			scanf("%d",&x);
			int w=lower_bound(a,a+n,x)-a;
			if(a[w]==x)
				printf("%d found at %d\n",x,w+1);
			else
				printf("%d not found\n",x);
		}
	}
	return 0;
}
