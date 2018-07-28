#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stack>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<math.h>
#include<ctype.h>
#define mem(a,b) memset(a,b,sizeof(a))
#include<algorithm>
using namespace std;
const int N=40006;
typedef long long LL;
int l[N],r[N],vis[N],num;
vector<int>v[N];
void dfs(int x)
{
    vis[x]=1;
    l[x]=num++;
    int len=v[x].size();
    for(int i=0; i<len; i++)
    {
        int k=v[x][i];
        if(!vis[k])
            dfs(k);
    }
    r[x]=num-1;
   // printf("l[%d]=%d,r[%d]=%d,num=%d\n",x,l[x],x,r[x],num);
}
int main()
{
    int n,q,a,b,rank1;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a,&b);
        if(b==-1)
            rank1=a;
        else
            v[b].push_back(a);
    }
    num=0;
    mem(l,0);
    mem(r,0);
    dfs(rank1);
    scanf("%d",&q);
    for(int i=1; i<=q; i++)
    {
        scanf("%d%d",&a,&b);
        if(l[a]<=l[b]&&r[a]>=r[b])
            puts("1");
        else if(l[a]>=l[b]&&r[a]<=r[b])
            puts("2");
        else
            puts("0");
    }
    return 0;
}
