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
int dfs(int m,int n)
{
    if(m==0||n==1)
        return 1;
    if(n>m)
        return dfs(m,m);
    return dfs(m,n-1)+dfs(m-n,n);
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        printf("%d\n",dfs(m,n));
    }
    return 0;
}
