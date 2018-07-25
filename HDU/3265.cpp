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
#define N 50200
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct Seg
{
    int l,r,h;
    int f;
    Seg() {}
    Seg(int a,int b,int c,int d):l(a),r(b),h(c),f(d) {}
    bool operator < (const Seg &cmp) const
    {
        return h<cmp.h;
    }
} e[N<<3];
struct node
{
    int cnt;
    ll len;
} t[N<<2];
int X[N<<3];
void pushdown(int l,int r,int rt)
{
    if(t[rt].cnt)
        t[rt].len=X[r+1]-X[l];
    else if(l==r)
        t[rt].len=0;
    else
        t[rt].len=t[rt<<1].len+t[rt<<1|1].len;
}
void update(int L,int R,int l,int r,int rt,int val)
{
    if(L>R) return;//重要，要排除这种情况
    if(L<=l&&r<=R)
    {
        t[rt].cnt+=val;
        pushdown(l,r,rt);
        return;
    }
    int m=(l+r)>>1;
    if(L<=m) update(L,R,lson,val);
    if(R>m) update(L,R,rson,val);
    pushdown(l,r,rt);
}
int main()
{
    int n,q;
    int a1,b1,c1,d1,a2,b2,c2,d2;
    while(~scanf("%d",&n)&&n)
    {
        mem(t,0);
        int num=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2);
            X[num]=a1;
            e[num++]=Seg(a1,c1,b1,1);
            X[num]=c1;
            e[num++]=Seg(a1,c1,b2,-1);
            X[num]=a1;
            e[num++]=Seg(a1,c1,d2,1);
            X[num]=c1;
            e[num++]=Seg(a1,c1,d1,-1);
            X[num]=a1;
            e[num++]=Seg(a1,a2,b2,1);
            X[num]=a2;
            e[num++]=Seg(a1,a2,d2,-1);
            X[num]=c2;
            e[num++]=Seg(c2,c1,b2,1);
            X[num]=c1;
            e[num++]=Seg(c2,c1,d2,-1);
        }
        sort(X,X+num);
        sort(e,e+num);
        int m=unique(X,X+num)-X;
        ll ans=0;
        for(int i=0; i<num; i++)
        {
            int l=lower_bound(X,X+m,e[i].l)-X;
            int r=lower_bound(X,X+m,e[i].r)-X-1;
            update(l,r,0,m,1,e[i].f);
            ans+=(ll)t[1].len*(e[i+1].h-e[i].h);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
