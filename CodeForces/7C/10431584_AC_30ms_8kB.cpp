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
#define ll long long
using namespace std;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
  if(b==0)
  {
      x=1;
      y=0;
      return a;
  }
  ll r=exgcd(b,a%b,x,y);
  ll t=x;
  x=y;
  y=t-a/b*y;
  return r;
}
int main()
{
  ll a,b,c,x,y;
  scanf("%lld%lld%lld",&a,&b,&c);
  c=-c;
  ll m=exgcd(a,b,x,y);
  if(c%m)
      puts("-1");
  else
      printf("%lld %lld\n",x*c/m,y*c/m);
  return 0;
}
