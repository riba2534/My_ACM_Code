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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=1e5+20;
int a[N],b[N],c[N];
int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        int len1=0,len2=0;
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n; i++)
        {
            int p=upper_bound(b,b+len1,a[i])-b;
            b[p]=a[i];
            if(p==len1)
                len1++;
        }
        for(int i=n-1; i>=0; i--)
        {
            int p=upper_bound(c,c+len2,a[i])-c;
            c[p]=a[i];
            if(p==len2)
                len2++;
        }
        if(n-k<=len1||n-k<=len2)
            puts("A is a magic array.");
        else
            puts("A is not a magic array.");
    }
    return 0;
}
