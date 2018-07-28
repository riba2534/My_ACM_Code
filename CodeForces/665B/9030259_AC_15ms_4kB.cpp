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
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 111111
#define M 1000000
#define ll long long
using namespace std;
int main()
{
    int n,m,k,j,l,x,ans;
    int a[110];
    ans=0;
    cin>>n>>m>>k;
    for(int i=1; i<=k; i++)
        cin>>a[i];
    for(int i=1; i<=n*m; i++)
    {
        cin>>x;
        for(j=1; j<=k; j++)
            if (a[j]==x)
                break;
        ans+=j;
        for(l=j; l>=2; l--)
            a[l]=a[l-1];
        a[1]=x;
    }
    cout<<ans<<endl;
    return 0;
}