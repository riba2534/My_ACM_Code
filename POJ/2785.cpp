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
const int N=4000+20;
int a[N],b[N],c[N],d[N],tot;
int e[N*N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        tot=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                e[tot++]=a[i]+b[j];
            }
        }
        sort(e,e+tot);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int num=c[i]+d[j];
                ans+=upper_bound(e,e+tot,-num)-lower_bound(e,e+tot,-num);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
