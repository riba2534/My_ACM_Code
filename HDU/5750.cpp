#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 100000+10
#define M 1000000+10
#define LL long long
using namespace std;
LL p[N],c[M];
void sushu()//ÏßÐÔÉ¸·¨
{
    LL tot=0;
    c[0]=1,c[1]=1;
    for(LL i=2;i<=M;i++)
    {
        if(!c[i])
            p[tot++]=i;
        for(LL j=0;j<tot&&i*p[j]<M;j++)
        {
            c[i*p[j]]=1;
            if(!(i%p[j]))
                break;
        }
    }
}
int main()
{
    LL t,n,k;
    sushu();
    scanf("%lld",&t);
    while(t--)
    {
        LL i;
        scanf("%lld%lld",&n,&k);
        for( i=0;;i++)
        {
            if(p[i]*k>=n)
                break;
            if(k%p[i]==0)
            {
                i++;
                break;
            }
        }
        printf("%lld\n",i);
    }
    return 0;
}
