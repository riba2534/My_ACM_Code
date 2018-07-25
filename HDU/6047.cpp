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
#define N 250010
#define ll long long
using namespace std;
const int mod=1e9+7;
int a[N*2],b[N],ma[N];
int main()
{
  int n;
  while(~scanf("%d",&n))
  {
      mem(ma,0);mem(a,0);
      int x;
      for(int i=1; i<=n; i++)
      {
          scanf("%d",&x);
          a[i]=x-i;
      }
      for(int i=n; i>=1; i--)
          ma[i]=max(a[i],ma[i+1]);//计算从i为开始，所能达到的最大值
      for(int i=1; i<=n; i++)
          scanf("%d",&b[i]);
      priority_queue<int>q;
      for(int i=1; i<=n; i++)
          q.push(ma[b[i]]);
      int ans=0,tmp=0;
      for(int i=n+1; i<=2*n; i++)
      {
          int s=q.top();
          if(tmp>s)
              a[i]=tmp-i;
          else
          {
              a[i]=s-i;
              q.pop();
          }
          ans=(ans+a[i]+i)%mod;
          tmp=max(tmp,a[i]);
      }
      printf("%d\n",ans%mod);
  }
  return 0;
}


