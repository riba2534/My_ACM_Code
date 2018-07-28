#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 100000+20
#define M 1000000+10
#define LL long long
using namespace std;
struct node
{
    int x,po;
}num[N];
int pre[N],next[N],c[N],list[N],n;
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int find(int i)
{
    int x1=-inf,x2=inf;
    if(pre[i]>=1)
        x1=list[pre[i]];
    if(next[i]<=n)
        x2=list[next[i]];
    return min(abs(list[i]-x1),abs(list[i]-x2));
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i].x);
            num[i].po=i;
        }
        int ed=num[n].x;
        sort(num+1,num+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            list[i]=num[i].x;
            c[num[i].po]=i;
            pre[i]=i-1;
            next[i]=i+1;
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            ans+=find(c[i]);
            pre[next[c[i]]]=pre[c[i]];
            next[pre[c[i]]]=next[c[i]];
        }
        printf("%d\n",ans+ed);
    }
	return 0;
}
