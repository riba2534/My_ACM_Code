#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000009
typedef long long ll;
const int N=105+20;
map<int,int>mp;
int num[N][N];
void init()
{
    for(int i=0; i<=100; i++)
        num[i][0]=1;
    for(int i=1; i<=100; i++)
        for(int j=1; j<=i; j++)
        {
            num[i][j]=(num[i-1][j]+num[i-1][j-1])%mod;
        }
}
int main()
{
    int n,m,k,x;
    init();
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        mp[x%k]++;
    }
    int ans=0;
    map<int,int>::iterator it;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if((*it).second>=m)
        {
            ans+=num[(*it).second][m];
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
