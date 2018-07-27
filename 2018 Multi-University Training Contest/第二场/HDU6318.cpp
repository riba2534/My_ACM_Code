#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
const ll N = 1e5 + 10;
const ll inf = 0x3f3f3f3f;
ll sum;
ll a[N],b[N];
void mix(ll start,ll mid,ll ed)
{
    ll i=start,j=mid+1,k=0;
    while(i<=mid&&j<=ed)
    {
        if(a[i]<=a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            sum+=mid+1-i;
            b[k++]=a[j++];
        }
    }
    while(i!=mid+1)
        b[k++]=a[i++];
    while(j!=ed+1)
        b[k++]=a[j++];
    for(ll i=0; i<k; i++)
        a[start++]=b[i];
}
void mergesort(ll start,ll ed)
{
    ll mid=(start+ed)/2;
    if(start<ed)
    {
        mergesort(start,mid);
        mergesort(mid+1,ed);
        mix(start,mid,ed);
    }
}

int main()
{
    ll n,x,y;
    while(~scanf("%lld%lld%lld",&n,&x,&y))
    {
        sum=0;
        for(ll i=0; i<n; i++)
            scanf("%lld",&a[i]);
        mergesort(0,n-1);
        printf("%lld\n",sum*min(x,y));
    }
    return 0;
}
