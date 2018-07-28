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
int main()
{
	int t,n,q=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		while(n!=0)
		{
			sum++;
			n/=2;
		}
		printf("Case %d: %d\n",q++,sum);
	}
	return 0;
}