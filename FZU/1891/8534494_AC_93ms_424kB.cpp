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
#define N 50000+20
#define M 1000000+10
#define LL long long
using namespace std;
int a[N];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        mem(a,0);
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1; i<=n; i++)
        {
            if(i==1)
            {
                printf("%d",a[1]);
                continue;
            }
            if(!(i&1))
                swap(a[i],a[i+1]);
            printf(" %d",a[i]);
        }
        puts("");
    }
    return 0;
}
