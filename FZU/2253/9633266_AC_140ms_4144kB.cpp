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
#define N 8
#define M 12357
#define ll long long
using namespace std;
int a[1000000+50];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int sum=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)
			{
				sum++;
				a[i]=-1;
			}
			else
				a[i]=1;
		}
		int maxx=a[0],cnt=0;
		for(int i=0;i<n;i++)
		{
			if(cnt>0)
				cnt+=a[i];
			else
				cnt=a[i];
			maxx=max(maxx,cnt);
		}
		printf("%d\n",maxx+sum);
	}
	return 0;
}
