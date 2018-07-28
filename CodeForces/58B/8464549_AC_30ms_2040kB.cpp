#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N (2000+20)
#define M 200010
#define MOD (1000000000+7)
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
int main()
{
    int n,i;
    scanf("%d",&n);
    for (i=n; i; i--)
        if(n%i==0)
            printf("%d ",n=i);

    return 0;
}

