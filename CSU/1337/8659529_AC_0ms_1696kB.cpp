#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 20000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int main()
{
    LL x,y,q=1;
    while(~scanf("%lld%lld",&x,&y))
    {
        LL sum=0;
        for(LL i=x; i<=y; i++)
        {
            if((i*i*i)/10>y)break;
            for(LL j=i; j<=y; j++)
            {
                LL t=(i*i*i)+(j*j*j)-3;
                if(t/10>y)break;
                if(t/10<=y&&t%10==0)
                    sum++;
            }
        }
        sum*=2;
        printf("Case %lld: %lld\n",q++,sum);
    }
    return 0;
}
