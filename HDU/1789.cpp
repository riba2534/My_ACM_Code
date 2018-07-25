#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1010000)
#define ll long long
using namespace std;
struct node
{
    int time,score;
} a[1010];
int vis[1010];
bool cmp(node a,node b)
{
    if(a.score==b.score)
        return a.time<b.time;
    else
        return a.score>b.score;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        mem(vis,0);
        int sum=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i].time);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i].score);
            sum+=a[i].score;
        }
        sort(a,a+n,cmp);
        for(int i=0; i<n; i++)
        {
            if(!vis[a[i].time])
            {
                vis[a[i].time]=1;
                sum-=a[i].score;
            }
            else
            {
                for(int j=a[i].time; j>=1; j--)
                {
                    if(!vis[j])
                    {
                        vis[j]=1;
                        sum-=a[i].score;
                        break;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}



