#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int N=3e5+10;
int n,k;
struct node
{
    int l,r,id;
    bool friend operator < (node a,node b)
    {
        return a.r>b.r;
    }
} a[N];
bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}
priority_queue<node>q;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].id=i;
    }
    int ans=0,minr,maxl;
    sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; i++)
    {
        q.push(a[i]);
        if(q.size()>k)
            q.pop();
        if(q.size()==k)
        {
            maxl=a[i].l;
            if((q.top().r-maxl+1)>ans)
            {
                ans=q.top().r-maxl+1;
                minr=q.top().r;
            }
        }

    }

    printf("%d\n",ans);
    if(ans==0)
    {
        for(int i=1; i<=k; i++)
            printf("%d ",i);
        puts("");
    }
    else
    {
        for(int i=1; i<=n; i++)
            if(k&&a[i].l<=maxl&&a[i].r>=minr)
            {
                printf("%d ",a[i].id);
                k--;
            }
        puts("");
    }
    return 0;
}
