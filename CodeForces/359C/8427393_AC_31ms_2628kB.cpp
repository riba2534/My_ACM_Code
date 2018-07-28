#include<stdio.h>
#include<algorithm>
using namespace std;

#define min(a,b) (a<b?a:b)
#define LL long long int
#define maxn 100000+10
#define g 1000000007
LL a[maxn];

LL quick_mod(LL a,LL b)
{
    LL ans=1;
    a=a%g;
    while(b)
    {
        if(b&1)
            ans=ans*a%g;
        a=a*a%g;
        b>>=1;
    }
    return ans;
}

int main()
{
    LL x,n,i,sum=0;
    scanf("%lld%lld",&n,&x);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(i=0;i<n;i++)
        a[i]=sum-a[i];
    sort(a,a+n);
    LL ans,cnt=1;
    a[n]=-1;
    for(i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        {
            if(cnt%x)
            {
                ans=a[i-1];
                break;
            }
            else
            {
                cnt/=x;
                a[i-1]+=1;
                i--;
            }
        }
        else cnt++;
    }
    ans=min(ans,sum);
    printf("%lld\n",quick_mod(x,ans));
    return 0;
}