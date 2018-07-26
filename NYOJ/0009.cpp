 
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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=10000+50;
int lazy[N<<4];
int vis[N],li[N],ri[N],X[N<<2];
int cnt;
void pushdown(int rt)
{
    if(~lazy[rt])
    {
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
        lazy[rt]=-1;
    }
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]=c;
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
}
void query(int l,int r,int rt)
{
    if(~lazy[rt])
    {
        if(!vis[lazy[rt]])
            cnt++;
        vis[lazy[rt]]=1;
        return;
    }
    if(l==r) return;
    int m=(l+r)>>1;
    query(lson);
    query(rson);
}
int main()
{
    int t,n,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int num=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&li[i],&ri[i]);
            X[num++]=li[i];
            X[num++]=ri[i];
        }
        sort(X,X+num);
        int m=unique(X,X+num)-X;
        for(int i=m-1; i>=0; i--)
            if(X[i]!=X[i-1]+1)
                X[m++]=X[i-1]+1;
        sort(X,X+m);
        mem(lazy,-1);
        for(int i=0; i<n; i++)
        {
            int l=lower_bound(X,X+m,li[i])-X;
            int r=lower_bound(X,X+m,ri[i])-X;
            update(l,r,i,0,m,1);
        }
        mem(vis,0);
        cnt=0;
        query(0,m,1);
        printf("%d\n",cnt);
    }
    return 0;
}
        