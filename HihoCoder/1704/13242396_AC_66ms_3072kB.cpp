#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100000+7;
int a[N],n;
int sum[N];
int judge(int x)
{
    for(int i=x; i<=n; i++)
        if(sum[i]-sum[x-1]<1)
            return 0;
    for(int i=1; i<x; i++)
        if(sum[i]+sum[n]-sum[x-1]<1)
            return 0;
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum[i]=a[i]+sum[i-1];
    }
    if(sum[n]<1)
    {
        puts("-1");
        return 0;
    }
    int flag=0;
    for(int i=1; i<=n; i++)
        if(judge(i))
        {
            printf("%d\n",i);
            return 0;
        }
    puts("-1");
    return 0;
}
