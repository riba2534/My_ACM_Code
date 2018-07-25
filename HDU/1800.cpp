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
int a[3000+20];
int vis[3000+20];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        mem(vis,0);
        int sum=0;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                sum++;
                int m=a[i];
                for(int j=i+1;j<n;j++)
                {
                    if(!vis[j]&&a[j]<m)
                    {
                        vis[j]=1;
                        m=a[j];
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}


