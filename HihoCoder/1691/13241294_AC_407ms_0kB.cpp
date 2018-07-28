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
const int N=20+7;
int a[N],b[N],c[N];
char sa[N],sb[N];
int vis[N];
int main()
{
    int n,ans=inf;
    scanf("%d%s%s",&n,sa,sb);
    for(int i=n-1; i>=0; i--)
    {
        a[i+1]=sa[i]-'0';
        b[i+1]=sb[i]-'0';
    }
    for(int i=1; i<=n; i++)
        c[i]=i;
    do
    {
        mem(vis,0);
        int res=0;
        for(int i=1; i<=n; i++)
        {
            res+=min((a[i]-b[c[i]]+10)%10,(b[c[i]]-a[i]+10)%10);
            if(!vis[c[i]])
            {
                int cnt=0,x=c[i];
                while(!vis[x])
                {
                    cnt++;
                    vis[x]=1;
                    x=c[x];
                }
                res+=cnt-1;
            }
        }
        ans=min(ans,res);
    }
    while(next_permutation(c+1,c+1+n));
    printf("%d\n",ans);
    return 0;
}
