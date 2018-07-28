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
int a[N],b[N];
int main()
{
    int n,sum=1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int m=n-a[n-1];
    for(int i=n-2; i>=0; i--)
    {
        if(i+1<m)
            sum++;
        m=min(i+1-a[i],m);
    }
    printf("%d\n",sum);
    return 0;
}
