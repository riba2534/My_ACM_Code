#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include <map>
#include<iostream>
#include <cmath>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1000020)
#define ll long long
using namespace std;
struct node
{
    int l,w,flag;
} zz[5000+20];
bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.w<b.w;
    return a.l<b.l;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&zz[i].l,&zz[i].w);
            zz[i].flag=0;
        }
        sort(zz,zz+n,cmp);
        for(int i=0; i<n; i++)
        {
            if(!zz[i].flag)
            {
                zz[i].flag=1;
                int w=zz[i].w;
                sum++;
                for(int j=i+1;j<n;j++)
                {
                    if(!zz[j].flag&&zz[j].w>=w)
                    {
                        zz[j].flag=1;
                        w=zz[j].w;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
