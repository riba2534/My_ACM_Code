 
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
ll num[100];
void biao()
{
	num[1] = 2, num[2] = 3;
	for(ll i = 3; i <= 40; i++)
		num[i] = num[i - 1] + num[i - 2];
}
int main()
{
	ll t,m;
	biao();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&m);
		printf("%lld\n",num[m]);
	}
	return 0;
}
        