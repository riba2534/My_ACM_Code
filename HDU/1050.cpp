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
int vis[500];
int main()
{
    int t,n,a,b;
    scanf("%d",&t);
    while(t--)
    {
        mem(vis,0);
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            if(a>b)swap(a,b);
            if(a&1)a+=1;
            if(b&1)b+=1;
            for(int i=a;i<=b;i++)
                vis[i]++;
        }
        int maxx=0;
        for(int i=0; i<=500; i++)
            maxx=max(maxx,vis[i]);
        printf("%d\n",maxx*10);
    }
    return 0;
}
