//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <stdlib.h>
//#include <string>
//#include <map>
//#include <iostream>
//#include <set>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//using namespace std;
//#define mem(a,b) memset(a,b,sizeof(a))
//#define lson l,m,rt<<1
//#define rson m+1,r,rt<<1|1
//typedef long long ll;
//const int N=1e+6+50;
//int lazy[N<<2],sum[N<<2];
//void pushup(int rt)
//{
//    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
//}
//void pushdown(int rt,int m)
//{
//    if(lazy[rt])
//    {
//        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
//        sum[rt<<1]=(m-(m>>1))*lazy[rt];
//        sum[rt<<1|1]=(m>>1)*lazy[rt];
//        lazy[rt]=0;
//    }
//}
//void build(int l,int r,int rt)
//{
//    lazy[rt]=0;
//    sum[rt]=1;
//    if(l==r)
//    {
//        scanf("%d",&sum[rt]);
//
//    }
//}
//
//int main()
//{
//    int t,n,m;
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d%d",&n,&m);
//        build(1,n,1);
//        while(m--)
//        {
//            scanf("%d%d%d",&a,&b,&c);
//            update(a,b,c,1,n,1);
//        }
//        printf("Case %d: The total value of the hook is %d.\n",q++,sum[1]);
//    }
//    return 0;
//}
//
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
#define N 111111
#define M 1000000
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int lazy[4*N];//用来标记，为0表示没有被标记，以要更新的值来做标记
int sum[4*N];//sum[i]代表以i为根节点的和
void pushup(int rt)//向上更新和
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int rt,int m)//对某一个区间进行改变，如果被标记了，在查询的时候就得把改变传给子节点，因为查询的并不一定是当前区间
{
    //m为区间长度
    if(lazy[rt])
    {
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];//传递给子节点
        //更新左儿子和右儿子的和
        sum[rt<<1]=(m-(m>>1))*lazy[rt];
        sum[rt<<1|1]=(m>>1)*lazy[rt];
        lazy[rt]=0;//取消对当前节点的标记
    }
}
void build(int l,int r,int rt)
{
    lazy[rt]=0;//初始化左右节点都没有被标记
    //初始值都为1
    if(l==r)
    {
        sum[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        lazy[rt]=c;
        sum[rt]=c*(r-l+1);//更新代表某个区间的节点和
        //printf("sum[%d]=%d,L=%d,R=%d,c=%d,lazy[rt]=%d\n",rt,sum[rt],L,R,c,lazy[rt]);
        return;
    }
    pushdown(rt,r-l+1);//向下传递
    int m=(l+r)>>1;
    if(L<=m)  update(L,R,c,lson);
    if(R>m)   update(L,R,c,rson);
    pushup(rt);//向上传递更新和
}
int n,m,t,a,b,c,q=1;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        build(1,n,1);//建立线段树
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,n,1);//更新区间
        }
        printf("Case %d: The total value of the hook is %d.\n",q++,sum[1]);
    }
    return 0;
}
