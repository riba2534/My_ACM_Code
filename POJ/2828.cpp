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
#define N 200005
#define M 1000000
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int tree[4*N];//存储当前空间的空位置数
int sum[N];//存放对应位置的数
void pushup(int rt)
{
    tree[rt]=tree[rt<<1]+tree[rt<<1|1];//更新空位置数
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=1;//刚开始子节点的空位置数都为1
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int p,int val,int l,int r,int rt)
{
    if(l==r)
    {
        sum[l]=val;
        tree[rt]=0;
        return;
    }
    int m=(l+r)>>1;
    //printf("p=%d,rt=%d,tree[rt<<1(%d)]=%d\n",p,rt,rt<<1,tree[rt<<1]);
    if(tree[rt<<1]>=p)//当前节点的左子树的空格数大于等于要放的位置数，就搜索左子树，反之搜索右子树
        update(p,val,lson);
    else
        update(p-tree[rt<<1],val,rson);
    pushup(rt);
}
int n;
struct node
{
    int x,y;
} zz[N];
int main()
{
    while(~scanf("%d",&n))
    {
        build(1,n,1);
        for(int i=1; i<=n; i++)
            scanf("%d%d",&zz[i].x,&zz[i].y);
        for(int i=n; i>=1; i--)
        {
            update(zz[i].x+1,zz[i].y,1,n,1);//从后往前更新,建树是从1开始建的没有0，所以要给位置+1
        }
        for(int i=1;i<=n;i++)
        {
            if(i>1)printf(" ");
            printf("%d",sum[i]);
        }
        puts("");
    }
    return 0;
}
