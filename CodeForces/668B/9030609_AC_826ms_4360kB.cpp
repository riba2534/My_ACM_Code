#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("whatthefuck!!!")
#define N 1111111
#define M 1000000
#define ll longlong
using namespace std;
int ans[N];

int main()
{
    int p0=0,p1=1;
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0; i<q; ++i)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int x;
            scanf("%d",&x);
            p0=(p0+x+n)%n;
            p1=(p1+x+n)%n;
        }
        else
        {
            p0=p0^1;
            p1=p1^1;
        }
    }
    for(int i=0; i<n; i+=2)
    {
        ans[(p0+i)%n]=i+1;
    }
    for(int i=1; i<n; i+=2)
    {
        ans[(p1+i-1)%n]=i+1;
    }
    for(int i=0; i<n; ++i)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
