#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 999999999
typedef long long ll;
const int N=30+20;
int a[N][N],b[N][N],n;
int check(int s)
{
    mem(b,0);
    for(int c=0; c<n; c++)
    {
        if(s&(1<<c))
            b[0][c]=1;
        else if(a[0][c]==1)
            return inf;
    }
    for(int r=1; r<n; r++)
        for(int c=0; c<n; c++)
        {
            int sum=0;
            if(r>1)sum+=b[r-2][c];
            if(c>0)sum+=b[r-1][c-1];
            if(c<n-1)sum+=b[r-1][c+1];
            b[r][c]=sum%2;
            if(a[r][c]==1&&b[r][c]==0)
                return inf;
        }
    int cnt=0;
    for(int r=0; r<n; r++)
        for(int c=0; c<n; c++)
            if(a[r][c]!=b[r][c])
                cnt++;
    return cnt;
}
int main()
{
    int t,q=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int ans=inf;
        for(int s=0; s<(1<<n); s++)
        {
            ans=min(ans,check(s));
        }
        if(ans==inf)ans=-1;
        printf("Case %d: %d\n",q++,ans);
    }
    return 0;
}
