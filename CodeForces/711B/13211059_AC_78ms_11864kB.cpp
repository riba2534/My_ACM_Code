#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int N=1000+20;
ll e[N][N];
ll n,x1,y1,sum1,cnt,flag;
void calc()
{
    sum1=0;
    for(ll i=0; i<n; i++)
    {
        if(i!=x1)
        {
            for(ll j=0; j<n; j++)
                sum1+=e[i][j];
            break;
        }
    }
    cnt=sum1;
    for(ll i=0; i<n; i++)
    {
        if(i==x1)
        {
            for(ll j=0; j<n; j++)
                cnt-=e[i][j];
        }
    }
    e[x1][y1]=cnt;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=0; i<n; i++)
        for(ll j=0; j<n; j++)
        {
            scanf("%lld",&e[i][j]);
            if(e[i][j]==0)
            {
                x1=i;
                y1=j;
            }
        }
    if(n==1)
    {
        printf("1\n");
        return 0;
    }
    calc();
    if(cnt<1)
    {
        printf("-1\n");
        return 0;
    }
    flag=0;
    for(ll i=0; i<n; i++)
    {
        ll x=0,y=0;
        for(ll j=0; j<n; j++)
            x+=e[i][j];
        for(ll j=0; j<n; j++)
            y+=e[j][i];
        if(!(x==y&&x==sum1&&y==sum1))
        {
            printf("-1\n");
            return 0;
        }
    }
    ll sum2=0;
    ll i=0,j=0;
    while(i<n)
    {
        sum2+=e[i][j];
        i++;
        j++;
    }
    if(sum2!=sum1)
    {
        printf("-1\n");
        return 0;
    }
    sum2=0,i=0,j=n-1;
    while(i<n)
    {
        sum2+=e[i][j];
        i++;
        j--;
    }
    if(sum1!=sum2)
    {
        printf("-1\n");
        return 0;
    }
    printf("%lld\n",cnt);
    return 0;
}
