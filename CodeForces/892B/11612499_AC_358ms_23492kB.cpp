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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int MIN[N<<2];
void pushup(int rt)
{
    MIN[rt]=min(MIN[rt<<1],MIN[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        MIN[rt]=b[l];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int querymin(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return MIN[rt];
    int m=(l+r)>>1;
    int ans=inf;
    if(L<=m)
        ans=min(ans,querymin(L,R,lson));
    if(R>m)
        ans=min(ans,querymin(L,R,rson));
    return ans;
}

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        b[i]=i-a[i];
    }
    build(1,n,1);
    for(int i=1; i<n; i++)
    {
        int minnum=querymin(i+1,n,1,n,1);
        if(i>=minnum)sum++;
    }
    printf("%d\n",n-sum);
    return 0;
}
