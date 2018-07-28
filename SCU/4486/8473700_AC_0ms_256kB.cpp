#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cstring>
#include <string>
#define N 300
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
 LL n;
LL zz(int x)
{
    LL ans=1;
    for(int i=1;i<=x;i++)
        ans=ans*2;
    if(x==0)
        return 1;
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        LL sum=n*(n+1)/2;
        LL l=n;
        LL cnt=0;
        while(l!=1)
        {
            l/=2;
            cnt++;
        }
        LL num=0;
        for(LL i=0;i<=cnt;i++)
        {
            l=zz(i);
            num+=l;
        }
        LL mm=sum-2*num;
        printf("%lld\n",mm);
    }
    return 0;
}



