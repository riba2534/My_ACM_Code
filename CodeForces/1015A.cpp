#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=1e6+10;
int vis[N];
int main()
{
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&l,&r);
        for(int j=l; j<=r; j++)vis[j]=1;
    }
    vector<int>v;
    for(int i=1; i<=m; i++)
        if(!vis[i])
            v.push_back(i);
    printf("%d\n",v.size());
    for(auto num:v)
    {
        printf("%d ",num);
    }
    puts("");
    return 0;
}
