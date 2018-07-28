#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=2e5+5;
int n,k,A,m;
int a[N],b[N];
int erfen(int x)
{
    for(int i=1; i<=x; i++)
        b[i]=a[i];
    sort(b+1,b+x+1);
    int sum=0;
    b[0]=0,b[x+1]=n+1;
    for(int i=0; i<=x; i++)
        sum+=(b[i+1]-b[i])/(A+1);
    return sum>=k;
}
int main()
{
    while(~scanf("%d%d%d",&n,&k,&A))
    {
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
            scanf("%d",&a[i]);
        int l=1,r=m,ans;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(erfen(mid))
                l=mid+1;
            else
                r=mid-1;
        }
        printf("%d\n",erfen(l)?-1:l);
    }
    return 0;
}
