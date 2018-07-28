#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N (100000+20)
#define M 200010
#define MOD (1000000000+7)
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
LL a[100001];
LL power(LL a,LL n)
{
    LL s=1;
    while (n)
    {
        if (n&1)
            s=s*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return s;
}
int main()
{
    LL n;
    LL x,sum=0;
    scanf("%lld%lld",&n,&x);
    for (LL i=1; i<=n; ++i)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    LL ans=sum-a[n],cnt=0;
    for (LL k=a[n]; k; k--)
    {
        while (n&&a[n]==k)
        {
            n--;
            cnt++;
        }

        if (cnt%x)
            break;
        ans++;
        cnt/=x;
    }
    printf("%lld\n",power(x,ans));
    return 0;
}
