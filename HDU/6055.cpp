#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 250010
#define ll long long
using namespace std;

int vis[500][500];
struct Point
{
    int x,y;
} p[555];
int solve(Point a,Point b)
{
    int x=a.x-b.x;
    int y=a.y-b.y;
    int ans=0;
    //  printf("a.x=%d,a.y=%d,b.x=%d,b.y=%d\n",a.x-200,a.y-200,b.x-200,b.y-200);
    //  printf("(%d,%d),(%d,%d),x=%d,y=%d\n",a.x+y-200,a.y-x-200,b.x+y-200,b.y-x-200,x,y);
    //  printf("(%d,%d),(%d,%d),x=%d,y=%d\n",a.x-y-200,a.y+x-200,b.x-y-200,b.y+x-200,x,y);
    if(a.x+y>=0&&a.y-x>=0&&b.x+y>=0&&b.y-x>=0&&vis[a.x+y][a.y-x]&&vis[b.x+y][b.y-x])
        ans++;
    if(a.x-y>=0&&a.y+x>=0&&b.x-y>=0&&b.y+x>=0&&vis[a.x-y][a.y+x]&&vis[b.x-y][b.y+x])
        ans++;
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a+=200;
            b+=200;
            p[i].x=a;
            p[i].y=b;
            vis[a][b]=1;
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(i!=j)
                    ans+=solve(p[i],p[j]);
            }
        }
        printf("%d\n",ans/4);
    }
}
