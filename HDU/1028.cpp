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
const int N=1000+7;
int c1[N],c2[N];
void solve(int n)
{
    for(int i=0; i<=n; i++)
    {
        c1[i]=1;
        c2[i]=0;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            for(int k=0; k+j<=n; k+=i)
                c2[j+k]+=c1[j];
        }
        for(int j=0; j<=n; j++)
        {
            c1[j]=c2[j];
            c2[j]=0;
        }
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        solve(n);
        printf("%d\n",c1[n]);
    }
    return 0;
}