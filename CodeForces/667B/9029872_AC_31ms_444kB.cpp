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
#define N 111111
#define M 1000000
#define ll long long
using namespace std;
int a[N];
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
            sum+=a[i];
    }
    sort(a+1,a+n+1);
    sum-=a[n];
    if(sum>a[n])
        puts("0");
    else
        printf("%d\n",a[n]-sum+1);
        return 0;
}