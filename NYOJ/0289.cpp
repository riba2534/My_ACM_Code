 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1e3+10;
int dp[N],v;
int num[N],weight[N],value[N];
void bag01(int c,int w)
{
    for(int i=v; i>=c; i--)
        dp[i]=max(dp[i],dp[i-c]+w);
}
void bagall(int c,int w)
{
    for(int i=c; i<=v; i++)
        dp[i]=max(dp[i],dp[i-c]+w);
}
void multbag(int c,int w,int n)
{
    if(c*n>=v)
    {
        bagall(c,w);
        return;
    }
    int k=1;
    while(k<=n)
    {
        bag01(k*c,k*w);
        n-=k;
        k*=2;
    }
    bag01(n*c,n*w);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&v)&&(n||v))
    {
        mem(dp,0);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&weight[i],&value[i]);
        }
        for(int i=0; i<n; i++)
            bag01(weight[i],value[i]);
        printf("%d\n",dp[v]);
    }
    return 0;
}
        