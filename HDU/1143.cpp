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
#define N 2
#define M 19999997
#define ll long long
using namespace std;
ll ans[35];
void init()
{
    ans[0]=1;
    ans[1]=ans[3]=0;
    ans[2]=3;ans[4]=11;
    for(int i=5;i<=30;i++)
    {
        if(i&1) ans[i]=0;
        else ans[i]=ans[i-2]*4-ans[i-4];
    }
}
int main()
{
    int n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1) break;
        printf("%I64d\n",ans[n]);
    }
    return 0;
}
