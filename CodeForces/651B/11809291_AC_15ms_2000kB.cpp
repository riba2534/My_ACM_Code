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
const int N=1000+20;
int a[N],b[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    int sum=0;
    sort(b,b+N);
    for(int i=0; i<N-1; i++)
        sum+=b[i];
    printf("%d\n",sum);
    return 0;
}
