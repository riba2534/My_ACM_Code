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
#define N 200200
#define M 1000000
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 //位运算，|可以理解为+
int MAX[4*N];
int h,w,n;
void pushup(int rt)//更新该节点维护的值,求和
{
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
}
void build(int l,int r,int rt)//建立线段树
{
    MAX[rt]=w;
    if(l==r)return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
int query(int x,int l,int r,int rt)//
{
    if(l==r)
    {
        MAX[rt]-=x;//更新节点
        return l;
    }
    int m=(l+r)>>1;
    int ret;
    if(MAX[rt<<1]>=x)
        ret=query(x,lson);
    else
        ret=query(x,rson);
    pushup(rt);
    return ret;
}
int main()
{

    while(~scanf("%d%d%d",&h,&w,&n))//广告牌的高和宽，广告的个数
    {
        if(h>n)h=n;//使广告牌的高度和要贴的广告的总高度一样
        build(1,h,1);
        while(n--)
        {
            int x;
            scanf("%d",&x);
            if(MAX[1]<x)
                puts("-1");
            else
                printf("%d\n",query(x,1,h,1));//放置广告条并且更新节点
        }
    }
    return 0;
}
