 
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
const int N=50000+20;
int lsum[N<<2],rsum[N<<2],msum[N<<2],cover[N<<2];
/*
msum[rt]:当前端点代表的区间最大连续空房间的个数
lsum[rt]:当前端点代表的区间从左到最大连续空房间的个数
rsum[rt]:当前端点代表的区间从右到左最大连续空房间的个数
cover[rt]:lazy标记，-1代表不操作,0代表此区间置空,1代表置满
*/
void pushup(int rt,int m)//向上更新
{
    //更新当前端点从左到右的左子树和从右到左的右子树
    lsum[rt]=lsum[rt<<1];
    rsum[rt]=rsum[rt<<1|1];
    if(lsum[rt]==m-(m>>1))//当左子树区间住满
        lsum[rt]+=lsum[rt<<1|1];
    if(rsum[rt]==(m>>1))//当右子树区间住满
        rsum[rt]+=rsum[rt<<1];
    //这个大区间连续的个数为:这个区间的左右子树的最大连续长度和从左到右的右子树+从右到左的左子树
    msum[rt]=max(lsum[rt<<1|1]+rsum[rt<<1],max(msum[rt<<1],msum[rt<<1|1]));
}
void pushdown(int rt,int m)
{
    if(~cover[rt])//当存在延迟标记
    {
        cover[rt<<1]=cover[rt<<1|1]=cover[rt];
        msum[rt<<1]=lsum[rt<<1]=rsum[rt<<1]=cover[rt]?0:m-(m>>1);
        msum[rt<<1|1]=lsum[rt<<1|1]=rsum[rt<<1|1]=cover[rt]?0:(m>>1);
        cover[rt]=-1;
    }
}
void build(int l,int r,int rt)
{
    cover[rt]=-1;
    lsum[rt]=rsum[rt]=msum[rt]=r-l+1;
    if(l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        msum[rt]=lsum[rt]=rsum[rt]=c?0:r-l+1;//如果要增加人,就变成0,如果是消去人,就变成区间的长度
        cover[rt]=c;//进行lazy标记
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    pushup(rt,r-l+1);
}
int query(int w,int l,int r,int rt)//查询能放下w个位置的最左端点
{
    if(l==r) return l;
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(msum[rt<<1]>=w)
        return query(w,lson);
    else if(rsum[rt<<1]+lsum[rt<<1|1]>=w)//从右到左连续的左子树 +从左到右连续的右子树
        return m-rsum[rt<<1]+1;
    else
        return query(w,rson);
}
int main()
{
    int n,m,op,k,a,b;
    while(~scanf("%d%d",&n,&m))
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&k);
                if(msum[1]<k)//当整个区间连续房间数小于k时
                    puts("0");
                else
                {
                    int p=query(k,1,n,1);//查询最小的房间位置
                    printf("%d\n",p);
                    update(p,p+k-1,1,1,n,1);//更新区间[p,p+k-1]
                }
            }
            else if(op==2)
            {
                scanf("%d%d",&a,&b);
                update(a,a+b-1,0,1,n,1);//更新区间[a,a+b-1]
            }
        }
    }
    return 0;
}
        