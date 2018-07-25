#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
bool t[1050];
int pre[1050];
int find(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
//    int i=x,j;
//    while(pre[i]!=r)
//    {
//        j=pre[i];
//        pre[i]=r;
//        i=j;
//    }
    return r;
}
void mix(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
        pre[fy]=fx;
}
int main()
{
    int m,n,a,b,ans;
    while(scanf("%d%d",&n,&m)&&n)
    {
        for(int i=1; i<=n; i++)pre[i]=i;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&a,&b);
            mix(a,b);
        }
        mem(t,0);
        for(int i=1; i<=n; i++)
            t[find(i)]=1;
        int i;
        for(ans=0,i=1; i<=n; i++)
            if(t[i])
                ans++;
        printf("%d\n",ans-1);
    }
    return 0;
}
