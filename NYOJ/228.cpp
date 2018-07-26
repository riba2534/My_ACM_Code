 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 1001000
#define M 1000000
#define ll long long
using namespace std;
int a[N];
int main()
{
    int n,c,q;
    int mi,ni,ai;
    scanf("%d%d%d",&n,&c,&q);
    while(c--)
    {
        scanf("%d%d%d",&mi,&ni,&ai);
        a[mi]+=ai;
        a[ni+1]-=ai;
    }
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    for(int i=1;i<=n;i++)
        a[i]=(a[i]+a[i-1])%10003;
    while(q--)
    {
        scanf("%d%d",&mi,&ni);
        printf("%d\n",(a[ni]-a[mi-1]+10003)%10003);
    }


    return 0;
}
        