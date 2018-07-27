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
#define N 100100
#define M 1000000+10
#define ll long long
using namespace std;
struct node
{
    int x,y,pos;
}g[N];
int b[N];
int pre[N],pb[N];
bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x<b.x;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        mem(b,0);mem(pre,0);mem(pb,0);
        int len=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&g[i].x,&g[i].y);
            g[i].pos=i;
        }
        sort(g,g+n,cmp);
        int sb;
        for(int i=0;i<n;i++)
        {
            int p=lower_bound(b,b+len,g[i].y)-b;
            if(p==0)
                pre[i]=-1;
            else
                pre[i]=pb[p-1];
            pb[p]=i;
            b[p]=g[i].y;
            if(p==len)len++,sb=i;
        }
        printf("%d\n",len);
        int pp=0;//用来控制空格输出
        while(sb!=-1)
        {
            if(pp)printf(" ");
            pp++;
            printf("%d",g[sb].pos+1);
            sb=pre[sb];
        }
        puts("");
        if(t)puts("");
    }
    return 0;
}