#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int N=50000+10;
int sum[N<<2];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int add,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]+=add;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) update(p,add,lson);
    else update(p,add,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
        return sum[rt];
    int m=(l+r)>>1;
    int ans=0;
    if(L<=m) ans+=query(L,R,lson);
    if(R>m) ans+=query(L,R,rson);
    return ans;
}
int main()
{
    int t,n,a,b,q=1;
    char s[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        build(1,n,1);
        printf("Case %d:\n",q++);
        while(scanf("%s",s)&&s[0]!='E')
        {
            scanf("%d%d",&a,&b);
            if(s[0]=='Q')
                printf("%d\n",query(a,b,1,n,1));
            if(s[0]=='A')
                update(a,b,1,n,1);
            if(s[0]=='S')
                update(a,-b,1,n,1);
        }
    }
    return 0;
}
