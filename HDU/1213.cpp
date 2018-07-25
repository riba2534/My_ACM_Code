#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 1000+20
#define M 30000+20
#define MOD 1000000000+7
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int pre[N];
void init()
{
    for(int i=1; i<=n; i++)
        pre[i]=i;
}
int find(int x)
{
    if(x==pre[x])
        return x;
    else
    {
        pre[x]=find(pre[x]);
        return pre[x];
    }
}
void mix(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
        pre[fy]=pre[x];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        int a,b;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&a,&b);
            mix(a,b);

        }
        int sum=0;
        for(int i=1; i<=n; i++)
            if(pre[i]==i)
                sum++;
        printf("%d\n",sum);
    }
    return 0;
}
