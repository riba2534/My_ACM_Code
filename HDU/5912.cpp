#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
int a[20],b[20];
int main()
{
    int t,n,q=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<=n; i++)
            scanf("%d",&b[i]);
        int tmp,fz=a[n],fm=1;
        for(int i=n-1; i>=1; i--)
        {
            tmp=a[i]*fz+b[i+1]*fm;
            fm=fz;
            fz=tmp;
        }
        fm=b[1]*fm;
        int k=__gcd(fm,fz);
        printf("Case #%d: %d %d\n",q++,fm/k,fz/k);
    }
    return 0;
}

