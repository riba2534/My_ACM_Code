//#include <stdio.h>
//#include <string.h>
//#include <string>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define N 100000+20
//#define M 1000000+10
//#define LL long long
//using namespace std;
//struct node
//{
//    int x,po;
//} num[N];
//int pre[N],next[N],c[N],list[N],n;
//bool cmp(node a,node b)
//{
//    return a.x<b.x;
//}
//int find(int i)
//{
//    int x1=-inf,x2=inf;
//    if(pre[i]>=1)
//        x1=list[pre[i]];
//    if(next[i]<=n)
//        x2=list[next[i]];
//    return min(abs(list[i]-x1),abs(list[i]-x2));
//}
//int main()
//{
//    while(~scanf("%d",&n))
//    {
//        for(int i=1; i<=n; i++)
//        {
//            scanf("%d",&num[i].x);
//            num[i].po=i;
//        }
//        int ed=num[n].x;
//        sort(num+1,num+n+1,cmp);
//        for(int i=1; i<=n; i++)
//        {
//            list[i]=num[i].x;
//            c[num[i].po]=i;
//            pre[i]=i-1;
//            next[i]=i+1;
//        }
//        int ans=0;
//        for(int i=1; i<n; i++)
//        {
//            ans+=find(c[i]);
//            pre[next[c[i]]]=pre[c[i]];
//            next[pre[c[i]]]=next[c[i]];
//        }
//        printf("%d\n",ans+ed);
//    }
//    return 0;
//}


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
#define inf 2000000000
#define N 100000+20
#define M 1000000+10
#define LL long long
using namespace std;
int n,pre[N],next[N],ff[N];
struct node
{
    int x,po;
}zz[N];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int find(int i)
{
    return min(abs(zz[i].x-zz[pre[i]].x),abs(zz[i].x-zz[next[i]].x));
}
void del(int i)
{
    pre[next[i]]=pre[i];
    next[pre[i]]=next[i];
}

int main()
{
    while(~scanf("%d",&n))
    {
        zz[0].x=-inf;
        zz[n+1].x=inf;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&zz[i].x);
            zz[i].po=i;
        }
        int ans=zz[n].x;
        sort(zz+1,zz+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            ff[zz[i].po]=i;
            pre[i]=i-1;
            next[i]=i+1;
        }
        for(int i=1;i<=n-1;i++)
        {
            ans+=find(ff[i]);
          //  printf("ans=%d ff[%d]=%d\n",ans,i,ff[i]);
            del(ff[i]);
          //  printf("%d %d\n",pre[3],next[3]);
        }
        printf("%d\n",ans);

    }
    return 0;
}
