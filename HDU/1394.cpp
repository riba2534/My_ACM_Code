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
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 1000020
#define M 1000000
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 //位运算，|可以理解为+
int sum[4*N];
void pushup(int rt)//更新该节点维护的值,求和
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)//建立线段树
{
    sum[rt]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void update(int p,int l,int r,int rt)//单点更新
{
    if(l==r)
    {
        sum[rt]++;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m)
        update(p,lson);
    else
        update(p,rson);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)//要查询的区间和当前的左右节点和根节点
{
    if(L<=l&&r<=R)//[l,r]∈[L,R]
    {
        return sum[rt];
    }
    int m=(l+r)>>1;//找中间点
    int ret=0;
    if(L<=m)  ret+=query(L,R,lson);
    if(R>m)   ret+=query(L,R,rson);
    return ret;
}
int x[N];
int main()
{
   int n;
   while(~scanf("%d",&n))
   {
       build(0,n-1,1);//建立一棵空树
       int cnt=0;
       for(int i=0;i<n;i++)
       {
           scanf("%d",&x[i]);
           cnt+=query(x[i],n-1,0,n-1,1);//返回比x[i]大的个数
          // printf("cnt=%d\n",cnt);
           update(x[i],0,n-1,1);//插入x[i]
       }
       int ret=cnt;
       for(int i=0;i<n;i++)
       {
           cnt+=n-x[i]-x[i]-1;//递推式
           ret=min(ret,cnt);
       }
       printf("%d\n",ret);
   }
    return 0;
}
