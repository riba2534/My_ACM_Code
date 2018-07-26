 
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
#define N 1000000+20
#define M 1000000+10
#define LL long long
using namespace std;
LL sum;
LL a[N],b[N];
void mix(LL start,LL mid,LL end)
{
    LL i=start,j=mid+1,k=0;
    while(i<=mid&&j<=end)
    {
      //  printf("i=%d,j=%d\n",i,j);
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
    while(j!=end+1)
        b[k++]=a[j++];
    for(LL i=0; i<k; i++)
        a[start++]=b[i];

}

void mergesort(LL start,LL end)
{
    //printf("%d %d \n",start,end);
    LL mid=(start+end)/2;
    if(start<end)
    {
        mergesort(start,mid);
        mergesort(mid+1,end);
        mix(start,mid,end);
    }
}

int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
        LL n;
        sum=0;
        scanf("%lld",&n);
        for(LL i=0; i<n; i++)
            scanf("%lld",&a[i]);
        mergesort(0,n-1);
        printf("%lld\n",sum);
    }
    return 0;
}
        