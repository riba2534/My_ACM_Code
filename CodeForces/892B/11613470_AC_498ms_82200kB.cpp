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
#define ll long long
using namespace std;
const int N=1e6+20;
int a[N];
int minsum[N][20];
void RMQ(int num)
{
    for(int j = 1; j < 20; ++j)
        for(int i = 1; i <= num; ++i)
            if(i + (1 << j) - 1 <= num)
            {
                minsum[i][j] = min(minsum[i][j - 1], minsum[i + (1 << (j - 1))][j - 1]);
            }
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        minsum[i][0]=i-a[i];
    }
    RMQ(n);
    for(int i=1; i<n; i++)
    {
        int k=(int)(log(n-(i+1)+1.0)/log(2.0));
        int minnum=min(minsum[i+1][k],minsum[n-(1<<k)+1][k]);
        if(i>=minnum)sum++;
    }
    printf("%d\n",n-sum);
    return 0;
}
