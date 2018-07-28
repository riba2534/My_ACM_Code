#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
const int N=2e5+10;
int n,m;
int a[N],sub[N],num[N];
int MAX[N<<2],id[N<<2];
void pushup(int rt)
{
    int ma1=MAX[rt<<1];
    int ma2=MAX[rt<<1|1];
    if(ma1>ma2)
    {
        MAX[rt]=ma1;
        id[rt]=id[rt<<1];
    }
    else
    {
        MAX[rt]=ma2;
        id[rt]=id[rt<<1|1];
    }
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        MAX[rt]=num[l];
        id[rt]=l;
        // printf("MAX[%d]=%d,id[%d]=%d\n",rt,num[l],rt,l);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
struct node
{
    int maxx;//最大值
    int id;//最大值的位置
};
node maxnode(node a,node b)//求出两个结构体的大小
{
    node res;
    if(a.maxx>b.maxx)
    {
        res.maxx=a.maxx;
        res.id=a.id;
    }
    else
    {
        res.maxx=b.maxx;
        res.id=b.id;
    }
    return res;
}
node query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        node res;
        res.maxx=MAX[rt];
        res.id=id[rt];
        return res;
    }
    int m=(l+r)>>1;
    node ans;
    ans.maxx=0;
    if(L<=m) ans=maxnode(ans,query(L,R,lson));
    if(R>m)  ans=maxnode(ans,query(L,R,rson));
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    sub[1]=inf;
    num[1]=1;
    for(int i=2; i<=n; i++)
    {
        sub[i]=a[i]-a[i-1];
        num[i]=(sub[i]==sub[i-1])?num[i-1]+1:2;
    }
    build(1,n,1);//对num[i]建立线段树
    int l,r;
    while(m--)
    {
        scanf("%d%d",&l,&r);
        if(r-l+1<=2)//当区间长度小于等于2
            printf("%d\n",r-l+1);
        else
        {
            node ans=query(l,r,1,n,1);//求出当前区间的最大值和位置
            if(ans.maxx<=ans.id-l+1)//最大值在覆盖范围内
            {
                printf("%d\n",ans.maxx);
            }
            else
            {
                int now_max=ans.id-l+1;//id的左边有多少个
                node res=query(ans.id+1,r,1,n,1);//算出右边最大的
                printf("%d\n",max(now_max,res.maxx));
            }
        }
    }
    return 0;
}
